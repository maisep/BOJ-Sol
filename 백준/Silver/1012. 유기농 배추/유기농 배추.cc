#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;

int main() {
	int T;
	cin >> T;

	int M, N, K;
	for (int t = 0; t < T; t++) {
		cin >> M >> N >> K;

		int X, Y;
		vector<vector<int>> field(N, vector<int>(M));
		vector<vector<bool>> visited(N, vector<bool>(M));
		int answer = 0;
		for (int k = 0; k < K; k++) {
			cin >> X >> Y;
			field[Y][X] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (field[i][j] && !visited[i][j]) {
					q.push({ i, j });
					visited[i][j] = false;
					answer++;

					while (!q.empty()) {
						pair<int, int> xy = q.front();
						q.pop();
						int x = xy.second;
						int y = xy.first;

						for (int a = 0; a < 4; a++) {
							int nx = x + dx[a];
							int ny = y + dy[a];

							if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
								continue;
							}
							if (visited[ny][nx] || !field[ny][nx]) {
								continue;
							}
							q.push({ ny, nx });
							visited[ny][nx] = true;
						}
					}
				}
			}
		}
		cout << answer << endl;
	}
	
	return 0;
}