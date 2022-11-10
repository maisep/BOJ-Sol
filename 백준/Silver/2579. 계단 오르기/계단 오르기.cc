#include <iostream>

using namespace std;

int dp[301];
int score[301];

int main() {
    int N;
    
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int p;

        cin >> p;
        
        score[i] = p;
    }

    dp[1] = score[1];
    dp[2] = score[2] + dp[1];
    for (int i = 3; i <= N; i++) {
        dp[i] = max(dp[i - 3] + score[i - 1] + score[i], dp[i - 2] + score[i]);
    }

    cout << dp[N] << endl;

    return 0;
}