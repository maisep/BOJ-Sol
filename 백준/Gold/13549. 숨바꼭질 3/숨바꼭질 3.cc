#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'
#define INF 123456789

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, N });
	vector<int> dist(100001, INF);
	dist[N] = 0;

	while (!pq.empty()) {
		pair<int, int> p = pq.top();
		pq.pop();
		int n = p.second;

		if (n * 2 <= 100000) {
			if (dist[n * 2] > dist[n]) {
				dist[n * 2] = dist[n];
				pq.push({ -dist[n * 2], n * 2 });
			}
		}

		if (n + 1 <= 100000) {
			if (dist[n + 1] > dist[n] + 1) {
				dist[n + 1] = dist[n] + 1;
				pq.push({ -dist[n + 1], n + 1 });
			}
		}

		if (n - 1 >= 0) {
			if (dist[n - 1] > dist[n] + 1) {
				dist[n - 1] = dist[n] + 1;
				pq.push({ -dist[n - 1], n - 1 });
			}
		}
	}

	cout << dist[K] << endl;

	return 0;
}