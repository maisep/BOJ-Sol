#include <iostream>

using namespace std;

int c_1 = 0;
int c_2 = 0;

long long f[41];

long long fib(int n) {
    if (n == 1 || n == 2) {
        c_1++;
        return 1;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

long long fibonacci(int n) {
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        c_2++;
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

int main() {
    int n;
    cin >> n;

    fib(n);
    fibonacci(n);
    
    cout << c_1 << " " << c_2 << endl;

    return 0;
}