#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int N, M;
int maze[101][101];
int visited[101][101];
queue<pair<int, int>> q;

int main() {
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        string tmp = "";
        cin >> tmp;
        for (int j = 1; j <= M; j++) {
            maze[i][j] = tmp[j - 1] - '0';
        }
    }
    
    q.push({ 1, 1 });
    visited[1][1] = true;
    
    while (!q.empty()) {
        pair<int, int> xy = q.front();
        int x = xy.first;
        int y = xy.second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 1 || nx > N || ny < 1 || ny > M)
                continue;
            if (!maze[nx][ny] || visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push({ nx, ny });
            maze[nx][ny] = maze[x][y] + 1;
        }
    }
    
    cout << maze[N][M] << endl;
    
    return 0;
 }