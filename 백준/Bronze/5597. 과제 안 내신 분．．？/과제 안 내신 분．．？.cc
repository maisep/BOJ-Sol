#include <iostream>

using namespace std;

int num[31];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    for (int i = 0; i < 28; i++) {
        cin >> n;
        num[n] = n;
    }

    for (int i = 1; i <= 30; i++) {
        if (num[i] == 0) {
            cout << i << '\n';
        }
    }

    return 0;
}