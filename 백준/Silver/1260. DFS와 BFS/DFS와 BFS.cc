#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> grp;
vector<bool> d_visited;
vector<bool> b_visited;
queue<int> q;
int N, M, R;

void dfs(int r) {
    d_visited[r] = true;
    printf("%d ", r);

    int g_size = grp[r].size();
    for (int i = 0; i < g_size; i++) {
        if (!d_visited[grp[r][i]]) {
            dfs(grp[r][i]);
        }
    }
}

void bfs(int r) {
    b_visited[r] = true;
    q.push(r);

    while (!q.empty()) {
        int n = q.front();
        q.pop();
        printf("%d ", n);

        int g_size = grp[n].size();
        for (int i = 0; i < g_size; i++) {
            if (!b_visited[grp[n][i]]) {
                q.push(grp[n][i]);
                b_visited[grp[n][i]] = true;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &R);

    grp.resize(N + 1);
    d_visited.resize(N + 1);
    b_visited.resize(N + 1);
    int n1;
    int n2;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &n1, &n2);
        grp[n1].push_back(n2);
        grp[n2].push_back(n1);
    }
    for (int i = 1; i <= N; i++) {
        sort(grp[i].begin(), grp[i].end());
    }

    dfs(R);
    printf("\n");
    bfs(R);

    return 0;
}