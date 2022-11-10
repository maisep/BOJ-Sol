#include <iostream>

using namespace std;

int num[1000000];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int min = 1234567890;
    int max = -1234567890;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        if (num[i] < min) {
            min = num[i];
        }
        if (num[i] > max) {
            max = num[i];
        }
    }

    cout << min << " " << max;

    return 0;
}