#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int answer = 0;

    vector<int> dp(N + 1, 0);
    vector<vector<int>> arr(N + 1, vector<int>(2, 0));

    for (int i = 0; i < N; i++) {
        cin >> arr[i + 1][0];
        cin >> arr[i + 1][1];
    }

    sort(arr.begin() + 1, arr.end());

    for (int i = 1; i <= N; i++) {
        dp[i] = 1;

        for (int j = 1; j < i; j++) {
            if (arr[j][1] < arr[i][1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        answer = max(answer, dp[i]);
    }

    cout << N - answer << endl;

    return 0;
}