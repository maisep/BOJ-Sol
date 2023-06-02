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

    vector<vector<int>> g(N + 1);
    vector<int> indegree(N + 1, 0);

    int A, B;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;

        g[A].push_back(B);
        indegree[B]++;
    }

    priority_queue<int> pq;
    for (int i = 1; i < N + 1; i++) {
        if (indegree[i] == 0)
            pq.push(i);
    }

    vector<int> answer;
    while (!pq.empty()) {
        int O = pq.top();
        pq.pop();
        answer.push_back(O);

        for (int i = 0; i < g[O].size(); i++) {
            indegree[g[O][i]]--;
            if (indegree[g[O][i]] == 0) {
                pq.push(g[O][i]);
            }
        }
    }

    for (int a : answer) {
        cout << a << " ";
    }

    return 0;
}