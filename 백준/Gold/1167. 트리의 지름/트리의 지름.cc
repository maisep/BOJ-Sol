#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

vector<pair<int, int>> tree[100001];
bool visited[100001];
int max_node;
int max_dist;

void DFS(int node, int dist) {
    if (max_dist < dist) {
        max_dist = dist;
        max_node = node;
    }

    visited[node] = true;

    for (int i = 0; i < tree[node].size(); i++) {
        if (!visited[tree[node][i].first]) {
            DFS(tree[node][i].first, tree[node][i].second + dist);
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int V;
    cin >> V;

    int a, b = -2, c;
    for (int i = 0; i < V; i++) {
        cin >> a;
        cin >> b;
        while (b != -1) {
            cin >> c;
            tree[a].push_back({ b, c });
            cin >> b;
        }
    }

    DFS(1, 0);
    max_dist = 0;
    for (int i = 1; i <= V; i++)
        visited[i] = false;
    DFS(max_node, 0);

    cout << max_dist << endl;

    return 0;
}