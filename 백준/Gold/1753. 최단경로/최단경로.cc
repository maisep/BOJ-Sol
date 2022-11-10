#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1987654321;

int main() {
    /*int V, E;
    cin >> V >> E;

    int K;
    cin >> K;

    priority_queue<pair <int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V + 1, INF);
    vector<vector<pair<int, int>>> g(V + 1);

    int u, v, w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
    }

    pq.push({ 0, K });
    dist[K] = 0;

    while (!pq.empty()) {
        pair<int, int> node = pq.top();
        int vertex = node.second;
        int weight = node.first;
        pq.pop();

        for (int i = 0; i < g[vertex].size(); i++) {
            int nv = g[vertex][i].first;
            int nw = g[vertex][i].second;

            if (dist[nv] > weight + nw) {
                pq.push({ nw, nv });
                dist[nv] = weight + nw;
            }
        }
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            cout << "INF" << "\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }
    }*/

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, Start;
    

    cin >> V >> E >> Start;
    vector<vector<pair<int, int>>> Vertex(V + 1);
    vector<int> Dist(V + 1);
    for (int i = 0; i < E; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        Vertex[a].push_back(make_pair(b, c));
    }
    for (int i = 1; i <= V; i++) Dist[i] = INF;

    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, Start));
    Dist[Start] = 0;

    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();

        for (int i = 0; i < Vertex[Cur].size(); i++)
        {
            int Next = Vertex[Cur][i].first;
            int nCost = Vertex[Cur][i].second;

            if (Dist[Next] > Cost + nCost)
            {
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (Dist[i] == INF) cout << "INF\n";
        else cout << Dist[i] << "\n";
    }
    

    return 0;
}