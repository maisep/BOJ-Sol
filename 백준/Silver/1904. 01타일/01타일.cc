#include <iostream>

using namespace std;

int dp[1000001];

int main() {
    int N;

    cin >> N;

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = ((dp[i - 1] % 15746) + (dp[i - 2] % 15746)) % 15746;
    }
    cout << dp[N] << endl;

    return 0;
}