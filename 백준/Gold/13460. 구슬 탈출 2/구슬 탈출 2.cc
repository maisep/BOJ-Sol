#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

struct Solve {
    int red_x, red_y;
    int blue_x, blue_y;
    int step;
};

char Board[10][10];
bool visit[10][10][10][10];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

Solve solve;

int move_ball(int& x, int& y, int d_x, int d_y) {
    int move_count = 0;
    while (Board[y + d_y][x + d_x] != '#' && Board[y][x] != 'O') {
        y += d_y;
        x += d_x;
        move_count++;
    }

    return move_count;
}

void bfs() {
    queue<Solve> q;
    q.push(solve);

    while (!q.empty()) {
        int rx = q.front().red_x;
        int ry = q.front().red_y;
        int bx = q.front().blue_x;
        int by = q.front().blue_y;
        int cnt = q.front().step;
        q.pop();

        if (cnt >= 10)
            break;

        for (int i = 0; i < 4; i++) {
            int next_rx = rx;
            int next_ry = ry;
            int next_bx = bx;
            int next_by = by;

            int red_move = move_ball(next_rx, next_ry, dx[i], dy[i]);
            int blue_move = move_ball(next_bx, next_by, dx[i], dy[i]);

            // 파란공이 구멍에 빠지면 안됨.
            if (Board[next_by][next_bx] == 'O')
                continue;

            if (Board[next_ry][next_rx] == 'O') {
                cout << cnt + 1;
                return;
            }

            // 공이 겹칠 수 없음
            if (next_rx == next_bx && next_ry == next_by) {
                // 빨간 공이 더 많이 움직임 == 파란 공은 이미 그 위치에 먼저 도착했음.
                if (red_move > blue_move) {
                    next_rx -= dx[i];
                    next_ry -= dy[i];
                }
                else {
                    next_bx -= dx[i];
                    next_by -= dy[i];
                }
            }

            if (!visit[next_ry][next_rx][next_by][next_bx]) {
                visit[next_ry][next_rx][next_by][next_bx] = true;

                q.push({ next_rx, next_ry, next_bx, next_by, cnt + 1 });
            }
        }
    }

    cout << -1;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    solve.step = 0;

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            cin >> Board[n][m];
            if (Board[n][m] == 'R') {
                solve.red_x = m;
                solve.red_y = n;
            }
            else if (Board[n][m] == 'B') {
                solve.blue_x = m;
                solve.blue_y = n;
            }
        }
    }

    bfs();

    return 0;
}