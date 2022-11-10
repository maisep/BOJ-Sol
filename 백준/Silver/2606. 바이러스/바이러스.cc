#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N, M;

int main() {
	int answer = 0;

	scanf("%d %d", &N, &M);

	vector<vector<int>> network(N + 1);
	vector<bool> infected(N + 1);
	
	int com1, com2;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &com1, &com2);
		network[com1].push_back(com2);
		network[com2].push_back(com1);
	}

	queue<int> q;
	q.push(1);
	infected[1] = true;

	while (!q.empty()) {
		int com = q.front();
		q.pop();

		int n_size = network[com].size();
		for (int i = 0; i < n_size; i++) {
			if (!infected[network[com][i]]) {
				q.push(network[com][i]);
				infected[network[com][i]] = true;
				answer++;
			}
		}
	}

	printf("%d\n", answer);

	return 0;
}