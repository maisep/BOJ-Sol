#include <iostream>

using namespace std;

int num[100];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, V;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    int count = 0;
    cin >> V;
    for (int i = 0; i < N; i++) {
        if (num[i] == V)
            count++;
    }
    cout << count;

    return 0;
}