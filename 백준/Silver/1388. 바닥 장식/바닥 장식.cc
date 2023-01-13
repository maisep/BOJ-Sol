#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    
    vector<string> tiles;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    string tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        tiles.push_back(tmp);
    }

    queue<pair<int, int>> q;
    int answer = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                q.push({ i, j });
                visited[i][j] = true;
                while (!q.empty()) {
                    pair<int, int> xy = q.front();
                    q.pop();
                    int x = xy.first;
                    int y = xy.second;
                    
                    if (tiles[x][y] == '-') {
                        if (y + 1 < M && !visited[x][y + 1] && tiles[x][y + 1] == '-') {
                            q.push({ x, y + 1 });
                            visited[x][y + 1] = true;
                        }
                    }
                    else {
                        if (x + 1 < N && !visited[x + 1][y] && tiles[x + 1][y] == '|') {
                            q.push({ x + 1, y });
                            visited[x + 1][y] = true;
                        }
                    }
                }
                answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}