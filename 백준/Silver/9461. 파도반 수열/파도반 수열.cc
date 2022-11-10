#include <iostream>

using namespace std;

long long dp[101];

int main() {
    int T;
    int N;

    cin >> T;
    dp[1] = dp[2] = dp[3] = 1;
    for (int i = 4; i <= 100; i++) {
        dp[i] = dp[i - 3] + dp[i - 2];
    }

    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << dp[N] << endl;
    }

    return 0;
}