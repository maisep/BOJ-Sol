#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> grp;
vector<bool> visited;
vector<int> order;
int N, M, R, num = 1;

bool cmp(int a, int b) {
    return a > b;
}

void dfs(int r) {
    visited[r] = true;
    order[r] = num++;

    int g_size = grp[r].size();
    for (int i = 0; i < g_size; i++) {
        if (!visited[grp[r][i]]) {
            dfs(grp[r][i]);
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &R);

    grp.resize(N + 1);
    visited.resize(N + 1);
    order.resize(N + 1);
    int n1;
    int n2;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &n1, &n2);
        grp[n1].push_back(n2);
        grp[n2].push_back(n1);
    }
    for (int i = 1; i <= N; i++) {
        sort(grp[i].begin(), grp[i].end(), cmp);
    }

    dfs(R);

    for (int i = 1; i <= N; i++) {
        printf("%d\n", order[i]);
    }

    return 0;
}