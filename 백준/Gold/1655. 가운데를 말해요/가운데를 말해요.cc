#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    priority_queue<int> max_pq;
    priority_queue<int> min_pq;

    int n;
    cin >> n;
    max_pq.push(n);
    cout << n << endl;
    for (int i = 1; i < N; i++) {
        cin >> n;
        if (max_pq.size() == min_pq.size()) {
            max_pq.push(n);
        }
        else {
            min_pq.push(-n);
        }

        if (max_pq.top() > -min_pq.top()) {
            int tmp = -min_pq.top();
            min_pq.pop();
            min_pq.push(-max_pq.top());
            max_pq.pop();
            max_pq.push(tmp);
        }

        cout << max_pq.top() << endl;
    }
    
    return 0;
}