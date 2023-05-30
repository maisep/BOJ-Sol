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

    int S;
    int before = -1;
    int s_no = -1;
    for (int i = 0; i < M; i++) {
        cin >> S;
        
        for (int j = 0; j < S; j++) {
            cin >> s_no;
            if (before != -1) {
                g[before].push_back(s_no);
                indegree[s_no]++;
            }
            before = s_no;
        }
        before = -1;
    }

    /*for (int i = 1; i < N + 1; i++) {
        cout << indegree[i];
    }

    cout << endl << endl;

    for (int i = 1; i < N + 1; i++) {
        cout << i << " : ";
        for (int a : g[i]) {
            cout << a << " ";
        }
        cout << endl;
    }*/

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

    if (answer.size() == N) {
        for (int a : answer) {
            cout << a << " ";
        }
    }
    else {
        cout << 0;
    }

    return 0;
}