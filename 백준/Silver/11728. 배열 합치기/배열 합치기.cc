#include <iostream>
#include <algorithm>
#include <queue>

#define endl '\n'

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    int NM = N + M;

    priority_queue<int> PQ;
    int a;
    for (int i = 0; i < NM; i++) {
        cin >> a;
        PQ.push(-a);
    }

    while (!PQ.empty()) {
        cout << -PQ.top() << " ";
        PQ.pop();
    }

    return 0;
}