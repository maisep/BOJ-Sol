#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

#define endl '\n'

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, K;
        cin >> N >> K;

        vector<int> build_time(N + 1);
        for (int n = 1; n <= N; n++) {
            cin >> build_time[n];
        }

        vector<vector<int>> build_list(N + 1);
        vector<int> indegree(N + 1);
        int X, Y;
        for (int k = 0; k < K; k++) {
            cin >> X >> Y;
            build_list[X].push_back(Y);
            indegree[Y]++;
        }

        int W;
        cin >> W;

        vector<int> time(N + 1);

        queue<int> q;
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                time[i] = build_time[i];
            }
        }

        while (!q.empty()) {
            int now_build = q.front();
            q.pop();

            for (int i = 0; i < build_list[now_build].size(); i++) {
                int next_build = build_list[now_build][i];
                indegree[next_build]--;
                
                time[next_build] = max(time[next_build], time[now_build] + build_time[next_build]);
                if (indegree[next_build] == 0) {
                    q.push(next_build);
                }
            }
        }

        cout << time[W] << endl;
    }

    return 0;
}