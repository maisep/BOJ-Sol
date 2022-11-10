#include <iostream>

using namespace std;

int dp[1001];
int arr[1001];

int main() {
    int N;
    cin >> N;
    int answer = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i + 1];
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = 1;

        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        answer = max(answer, dp[i]);
    }

    cout << answer << endl;
    
    return 0;
}