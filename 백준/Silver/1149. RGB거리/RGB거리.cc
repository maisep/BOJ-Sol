#include <iostream>

using namespace std;

const int INF = -1999999999;
int dp[1001][3];

int main() {
    int N;
    cin >> N;
    int RGB[3];

    cin >> dp[1][0];
    cin >> dp[1][1];
    cin >> dp[1][2];

    for (int i = 2; i <= N; i++) {
        cin >> RGB[0];
        cin >> RGB[1];
        cin >> RGB[2];

        dp[i][0] = min(dp[i - 1][1] + RGB[0], dp[i - 1][2] + RGB[0]);
        dp[i][1] = min(dp[i - 1][0] + RGB[1], dp[i - 1][2] + RGB[1]);
        dp[i][2] = min(dp[i - 1][0] + RGB[2], dp[i - 1][1] + RGB[2]);
    }

    cout << min(dp[N][0], min(dp[N][1], dp[N][2])) << endl;

    return 0;
}