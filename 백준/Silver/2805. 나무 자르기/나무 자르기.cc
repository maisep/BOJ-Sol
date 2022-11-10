#include <iostream>

#define endl '\n'

using namespace std;

long long tree[1000000];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    long long max_height = 0;
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        max_height = max(max_height, tree[i]);
    }

    long long start = 0;
    long long end = max_height;
    long long mid = (start + end) / 2;
    long long sum = 0;
    long long answer = -1;

    while (start <= end) {
        for (int i = 0; i < N; i++) {
            if (tree[i] >= mid) {
                sum += tree[i] - mid;
            }
        }

        if (sum >= M) {
            start = mid + 1;
            answer = max(answer, mid);
        }
        else {
            end = mid - 1;
        }
        mid = (start + end) / 2;
        sum = 0;
    }

    cout << answer << endl;
    
    return 0;
}