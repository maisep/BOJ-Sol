#include <iostream>

using namespace std;

int num[9];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int max = -1234567890;
    int max_idx = 0;
    for (int i = 0; i < 9; i++) {
        cin >> num[i];
        if (num[i] > max) {
            max = num[i];
            max_idx = i;
        }
    }

    cout << max << "\n" << max_idx + 1;

    return 0;
}