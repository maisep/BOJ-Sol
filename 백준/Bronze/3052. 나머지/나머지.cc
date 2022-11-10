#include <iostream>

using namespace std;

int num[42];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    for (int i = 0; i < 28; i++) {
        cin >> n;
        num[n % 42]++;
    }

    int count = 0;
    for (int i = 0; i < 42; i++) {
        if (num[i] != 0) {
            count++;
        }
    }
    cout << count;

    return 0;
}