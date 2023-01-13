#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n';

using namespace std;

vector<pair<int, int>> GRP[10001];
bool visit[10001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int V, E;
	cin >> V >> E;

	int A, B, C;
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		GRP[A].push_back({ -C, B });
		GRP[B].push_back({ -C, A });
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });

	long long weight_sum = 0;
	pair<int, int> p;
	int node;
	int weight;
	while (!pq.empty()) {
		p = pq.top();
		node = p.second;
		weight = -p.first;
		pq.pop();

		if (!visit[node]) {
			visit[node] = true;
			weight_sum += (long long)weight;
		}
		for (int i = 0; i < GRP[node].size(); i++) {
			if (!visit[GRP[node][i].second]) {
				pq.push(GRP[node][i]);
			}
		}
	}

	cout << weight_sum << endl;

	return 0;
}