#include <iostream>

using namespace std;

int num[10000];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, X;
    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
        if (num[i] < X) {
            cout << num[i] << " ";
        }
    }

    return 0;
}