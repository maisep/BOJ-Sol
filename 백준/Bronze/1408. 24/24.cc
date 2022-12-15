#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string A, B;
    cin >> A >> B;

    int A_h = stoi(A.substr(0, 2));
    int A_m = stoi(A.substr(3, 2));
    int A_s = stoi(A.substr(6, 2));
    int A_t = A_h * 3600 + A_m * 60 + A_s;

    int B_h = stoi(B.substr(0, 2));
    int B_m = stoi(B.substr(3, 2));
    int B_s = stoi(B.substr(6, 2));
    int B_t = B_h * 3600 + B_m * 60 + B_s;

    int ans_t = B_t - A_t;

    if (ans_t < 0) {
        ans_t += 86400;
    }
    int ans_h = ans_t / 3600;
    ans_t %= 3600;
    int ans_m = ans_t / 60;
    ans_t %= 60;
    int ans_s = ans_t;
    
    string answer;
    for (int t : { ans_h, ans_m, ans_s }) {
        if (t < 10) {
            answer += '0' + to_string(t) + ":";
        }
        else {
            answer += to_string(t) + ":";
        }
    }
    answer.pop_back();

    cout << answer << endl;

    return 0;
}