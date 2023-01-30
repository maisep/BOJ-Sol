#include <iostream>

#define endl '\n'

using namespace std;

long long gcd(long long x, long long y) {
    long long a;
    while (y != 0) {
        a = x % y;
        x = y;
        y = a;
    }

    return x;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long n, b;
    cin >> n >> b;

    long long x_sum = 0;
    long long y_sum = 0;
    long long x_a, y_a;
    for (long long i = 0; i < n; i++) {
        cin >> x_a >> y_a;
        x_sum += x_a;
        y_sum += (y_a - b);
    }

    if (x_sum == 0) {
        cout << "EZPZ" << endl;
    }
    else {
        if (y_sum % x_sum == 0) {
            cout << y_sum / x_sum << endl;
        }
        else {
            long long g = gcd(abs(x_sum), abs(y_sum));
            x_sum /= g;
            y_sum /= g;

            if (x_sum < 0)
                cout << -y_sum << "/" << -x_sum << endl;
            else
                cout << y_sum << "/" << x_sum << endl;
        }
    }

    return 0;
}
