#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

vector<pair<int, int>> tree[10001];
vector<bool> visited;
int max_len = 0;
int max_node = 0;

void dfs(int node, int dist) {
    if (max_len < dist) {
        max_len = dist;
        max_node = node;
    }

    visited[node] = true;

    for (int i = 0; i < tree[node].size(); i++) {
        if (!visited[tree[node][i].first]) {
            dfs(tree[node][i].first, dist + tree[node][i].second);
        }
    }    
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int a, b, c;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        tree[a].push_back({ b, c });
        tree[b].push_back({ a, c });
    }

    visited.assign(n + 1, false);
    dfs(1, 0);

    max_len = 0;

    visited.assign(n + 1, false);
    dfs(max_node, 0);

    cout << max_len << endl;

    return 0;
}