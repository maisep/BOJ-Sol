#include <iostream>

using namespace std;

int dp[2][1001];
int arr[1001];

int main() {
    int N;
    cin >> N;
    int answer = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i + 1];
    }

    // 앞에서 부터 점점 커지는 수열
    for (int i = 1; i <= N; i++) {
        dp[0][i] = 1;

        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[0][i] = max(dp[0][i], dp[0][j] + 1);
            }
        }
    }

    // 앞에서 부터 점점 작아지는 수열
    for (int i = N; i > 0; i--) {
        dp[1][i] = 1;

        for (int j = i; j <= N; j++) {
            if (arr[j] < arr[i]) {
                dp[1][i] = max(dp[1][i], dp[1][j] + 1);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        answer = max(answer, dp[0][i] + dp[1][i] - 1);
    }

    cout << answer << endl;
    
    return 0;
}