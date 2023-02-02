#include <iostream>
#include <vector>

#define endl '\n'
#define INF 1999999999

using namespace std;

int dp[501][501];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> matrix;
    int r, c;
    for (int i = 0; i < N; i++) {
        cin >> r >> c;
        matrix.push_back(r);
        if (i == N - 1) {
            matrix.push_back(c);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= N - i; j++) {
            int n = i + j;
            if (j == n)
                dp[j][n] = 0;
            else {
                dp[j][n] = INF;
                for (int k = j; k <= n - 1; k++) {
                    dp[j][n] = min(dp[j][n], dp[j][k] + dp[k + 1][n] + matrix[j - 1] * matrix[k] * matrix[n]);
                }
            }
        }
    }

    cout << dp[1][N] << endl;

    return 0;
}
