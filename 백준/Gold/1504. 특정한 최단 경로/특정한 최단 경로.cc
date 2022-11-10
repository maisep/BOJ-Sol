#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'
#define INF 123456789

using namespace std;


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, E;
    cin >> N >> E;

    vector<vector<pair<int, int>>> grp(N + 1);

    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        grp[a].push_back({ b, c });
        grp[b].push_back({ a, c });
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<vector<int>> dist(3, vector<int>(N + 1, INF));
    vector<int> sol = { 1, v1, v2 };

    priority_queue<pair<int, int>> pq;
    for (int s = 0; s < 3; s++) {
        dist[s][sol[s]] = 0;
        pq.push({ 0, sol[s] });

        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            int now_node = p.second;
            int now_weight = -p.first;

            for (int i = 0; i < grp[now_node].size(); i++) {
                int next_node = grp[now_node][i].first;
                int next_weight = grp[now_node][i].second;

                if (dist[s][next_node] > now_weight + next_weight) {
                    dist[s][next_node] = now_weight + next_weight;
                    pq.push({ -dist[s][next_node], next_node });
                }
            }
        }
    }

    int answer = min(dist[0][v1] + dist[1][v2] + dist[2][N], dist[0][v2] + dist[2][v1] + dist[1][N]);

    if (answer >= INF)
        cout << -1 << endl;
    else
        cout << answer << endl;

    return 0;
}