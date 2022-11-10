#include <iostream>
#include <vector>

using namespace std;

const int INF = -1999999999;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n, INF);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    dp[0] = v[0];
    int maxn = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(v[i], dp[i - 1] + v[i]);
        maxn = max(dp[i], maxn);
    }

    cout << maxn << endl;

    return 0;
}