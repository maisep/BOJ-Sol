#include <iostream>

using namespace std;

int dp[1000001];
const int INF = 1999999999;

void count(int N, int cnt) {
    if (N == 1) {
        return;
    }

    if (N % 3 == 0 && dp[N / 3] > cnt + 1) {
        dp[N / 3] = cnt + 1;
        count(N / 3, cnt + 1);
    }

    if (N % 2 == 0 && dp[N / 2] > cnt + 1) {
        dp[N / 2] = cnt + 1;
        count(N / 2, cnt + 1);
    }

    if (dp[N - 1] > cnt + 1) {
        dp[N - 1] = cnt + 1;
        count(N - 1, cnt + 1);
    }
}

int main() {
    int N;
    fill_n(dp, 1000001, INF);
    cin >> N;
    dp[N] = 0;

    count(N, 0);

    cout << dp[1] << endl;
    return 0;
}