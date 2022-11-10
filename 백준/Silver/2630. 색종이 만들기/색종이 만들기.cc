#include <iostream>

#define endl '\n'

using namespace std;

int paper[128][128];
int N;
int answer[2];

void cut(int a_s, int b_s, int K, int color) {
    if (K == 1) {
        if (paper[a_s][b_s] == color)
            answer[color]++;
        return;
    }

    bool check = true;
    for (int i = a_s; i < a_s + K && check; i++) {
        for (int j = b_s; j < b_s + K && check; j++) {
            if (paper[i][j] != color) {
                check = false;
            }
        }
    }

    if (check) {
        answer[color]++;
        return;
    }
    else {
        cut(a_s, b_s, K / 2, color);
        cut(a_s + K / 2, b_s, K / 2, color);
        cut(a_s, b_s + K / 2, K / 2, color);
        cut(a_s + K / 2, b_s + K / 2, K / 2, color);
    }
}



int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    cut(0, 0, N, 0);
    cut(0, 0, N, 1);

    cout << answer[0] << endl << answer[1] << endl;
    
    return 0;
}


