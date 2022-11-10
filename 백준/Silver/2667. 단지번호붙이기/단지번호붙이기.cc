#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	int answer = 0;

	cin >> N;

	vector<string> village;
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	vector<int> num_comp;

	string t = "";
	for (int i = 0; i < N; i++) {
		cin >> t;
		village.push_back(t);
	}
	
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (village[i][j] == '1' && !visited[i][j]) {
				int cnt = 1;
				q.push({ i, j });
				visited[i][j] = true;

				while (!q.empty()) {
					pair<int, int> xy = q.front();
					q.pop();

					int x = xy.first;
					int y = xy.second;

					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
							continue;
						}
						
						if (village[nx][ny] != '1' || visited[nx][ny]) {
							continue;
						}

						q.push({ nx, ny });
						visited[nx][ny] = true;
						cnt++;
					}
				}
				answer++;
				num_comp.push_back(cnt);
			}
		}
	}
	sort(num_comp.begin(), num_comp.end());

	cout << answer << endl;
	for (int n : num_comp) {
		cout << n << endl;
	}

	return 0;
}