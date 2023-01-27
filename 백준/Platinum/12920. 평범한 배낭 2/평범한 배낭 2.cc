#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int V[10001];
int C[10001];
int K[10001];
int dp[10001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> V[i] >> C[i] >> K[i];
    }

    vector<pair<int, int>> items;
    for (int i = 0; i < N; i++) {
        for (int j = K[i]; j > 0; j >>= 1) {
            int num = j - (j >> 1);
            items.push_back({ V[i] * num, C[i] * num });
        }
    }

    for (int i = 0; i < items.size(); i++) {
        for (int j = M; j >= items[i].first; j--) {
            dp[j] = max(dp[j], dp[j - items[i].first] + items[i].second);
        }
    }

    cout << dp[M] << endl;

    return 0;
}