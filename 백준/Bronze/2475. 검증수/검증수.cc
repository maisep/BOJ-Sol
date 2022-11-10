#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int A;
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        cin >> A;
        sum += A * A;
    }
    cout << sum % 10 << endl;

    return 0;
}