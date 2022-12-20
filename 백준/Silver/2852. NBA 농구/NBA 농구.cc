#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

int score[2] = { 0, 0 };
int win_time[2] = { 0, 0 };
int end_time = 2880;
int bef_win = 0;
int now_win = 0;
string win_start_time;

int get_win_team() {
    if (score[0] > score[1])
        return 1;
    else if (score[0] < score[1])
        return 2;
    else
        return 0;
}

int time_to_sec(string time) {
    int mini = (time[0] - '0') * 10 + (time[1] - '0');
    int secd = (time[3] - '0') * 10 + (time[4] - '0');

    return mini * 60 + secd;
}

string sec_to_time(int sec) {
    string time;
    int m = sec / 60;
    sec %= 60;
    
    for (int t : { m, sec }) {
        if (t < 10)
            time += "0" + to_string(t);
        else
            time += to_string(t);
        time += ":";
    }
    time.pop_back();

    return time;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int team;
    string time;
    for (int i = 0; i < N; i++) {
        cin >> team;
        cin >> time;
        score[team - 1]++;

        bef_win = now_win;
        now_win = get_win_team();
        // 어느 팀이 이기다가 비벼지면?
        if (bef_win && !now_win) {
            win_time[bef_win - 1] += time_to_sec(time) - time_to_sec(win_start_time);
        }
        // 비기고 있다가 어느 팀이 역전하면?
        else if (!bef_win && now_win) {
            win_start_time = time;
        }
        // 한 팀이 계속 이기는 중이라면?
        else {
            continue;
        }
    }

    if (now_win) {
        win_time[now_win - 1] += end_time - time_to_sec(win_start_time);
    }

    cout << sec_to_time(win_time[0]) << endl;
    cout << sec_to_time(win_time[1]) << endl;

    return 0;
}