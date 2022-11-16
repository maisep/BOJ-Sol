#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

bool visited[100001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;

    queue<pair<int, int>> q;
    q.push({ N, 0 });

    int answer = 0;
    int min_count = 987654321;
    while (!q.empty()) {
        pair<int, int> xc = q.front();
        q.pop();
        int x = xc.first;
        int c = xc.second;
        // 지금 위치까지 오는 다른 최단 경로의 존재 가능성이 있음.
        // 그래서 큐에 푸쉬할 때 방문 설정을 하는 것이 아닌,
        // 큐에서 팝되는 순간에 방문 설정을 함.
        visited[x] = true;

        if (x == K) {
            if (c < min_count) {
                answer = 1;
                min_count = c;
            }
            else if (c == min_count) {
                answer++;
            }
        }
        else {
            if (x + 1 <= 100000 && !visited[x + 1])
                q.push({ x + 1, c + 1 });
            if (x - 1 >= 0 && !visited[x - 1])
                q.push({ x - 1, c + 1 });
            if (x * 2 <= 100000 && !visited[x * 2])
                q.push({ x * 2, c + 1 });
        }
    }

    cout << min_count << endl;
    cout << answer << endl;

    return 0;
}