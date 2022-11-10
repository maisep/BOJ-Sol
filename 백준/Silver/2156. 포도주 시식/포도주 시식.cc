#include <iostream>

using namespace std;

int dp[10001];
int podoju[10001];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> podoju[i + 1];
    }

    dp[1] = podoju[1];
    dp[2] = dp[1] + podoju[2];

    for (int i = 3; i <= N; i++) {
        dp[i] = max(dp[i - 2] + podoju[i], dp[i - 3] + podoju[i - 1] + podoju[i]);
        dp[i] = max(dp[i - 1], dp[i]);
    }

    cout << dp[N] << endl;

    return 0;
}