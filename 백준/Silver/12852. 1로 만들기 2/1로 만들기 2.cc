#include <iostream>
#include <vector>

#define endl '\n'
#define INF 1999999999

using namespace std;

int dp[1000001];

void dfs(int n) {
    if (n == 1)
        return;

    if (n % 3 == 0 && n / 3 >= 1) {
        if (dp[n / 3] > dp[n] + 1) {
            dp[n / 3] = dp[n] + 1;
            dfs(n / 3);
        }
    }

    if (n % 2 == 0 && n / 2 >= 1) {
        if (dp[n / 2] > dp[n] + 1) {
            dp[n / 2] = dp[n] + 1;
            dfs(n / 2);
        }
    }

    if (n - 1 >= 1) {
        if (dp[n - 1] > dp[n] + 1) {
            dp[n - 1] = dp[n] + 1;
            dfs(n - 1);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        dp[i] = INF;
    }
    dfs(N);

    cout << dp[1] << endl;

    vector<int> v;
    int n = 1;
    v.push_back(n);
    while (n < N) {
        if (dp[n] - 1 == dp[n + 1]) {
            v.push_back(n + 1);
            n++;
        }
        else if (n * 2 <= N && dp[n] - 1 == dp[n * 2]) {
            v.push_back(n * 2);
            n *= 2;
        }
        else if (n * 3 <= N && dp[n] - 1 == dp[n * 3]) {
            v.push_back(n * 3);
            n *= 3;
        }
    }

    int v_s = v.size();
    for (int i = v_s - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }

    return 0;
}
