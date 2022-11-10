#include <iostream>

using namespace std;

long long dp[101][10];
const long long mod = 1000000000;

int main() {
    int N;
    fill_n(dp[1], 10, 1ll);
    cin >> N;
    dp[1][0] = 0ll;
    long long answer = 0ll;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][j] = (dp[i - 1][j + 1]) % mod;
            }
            else if (j == 9) {
                dp[i][j] = (dp[i - 1][j - 1]) % mod;
            }
            else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        answer += dp[N][i];
    }
    answer %= mod;

    cout << answer << endl;
    return 0;
}