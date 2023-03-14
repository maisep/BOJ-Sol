#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl '\n'

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> direct(N + 1);
    vector<int> indegree(N + 1);
    int A, B;
    for (int m = 0; m < M; m++) {
        cin >> A >> B;
        direct[A].push_back(B);
        indegree[B]++;
    }
    
    priority_queue<int> pq;
    for (int i = 1; i < N + 1; i++) {
        if (indegree[i] == 0) {
            pq.push(-i);
        }
    }

    while (!pq.empty()) {
        int Q = -pq.top();
        pq.pop();
        cout << Q << " ";

        for (int i = 0; i < direct[Q].size(); i++) {
            indegree[direct[Q][i]]--;
            if (indegree[direct[Q][i]] == 0) {
                pq.push(-direct[Q][i]);
            }
        }
    }
    

    return 0;
}