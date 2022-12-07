#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

vector<int> tree[100001];
bool visited[100001];
int parents[100001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        for (int i = 0; i < tree[n].size(); i++) {
            if (!visited[tree[n][i]]) {
                q.push(tree[n][i]);
                parents[tree[n][i]] = n;
                visited[tree[n][i]] = true;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << parents[i] << endl;
    }

    return 0;
}