#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dp[100001][101];

int main() {
    int N;
    int K;

    cin >> N >> K;

    vector<vector<int>> WV(N + 1, vector<int>(2, 0));

    for (int i = 1; i <= N; i++) {
        cin >> WV[i][0] >> WV[i][1];
        dp[WV[i][0]][1] = WV[i][1];
    }

    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            if (i >= WV[j][0]) {
                dp[i][j] = max(dp[i][j - 1], dp[i - WV[j][0]][j - 1] + WV[j][1]);
            }
            else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    cout << dp[K][N] << endl;

    return 0;
}