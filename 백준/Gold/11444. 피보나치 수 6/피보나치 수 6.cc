#include <iostream>
#include <unordered_map>

#define endl '\n'
#define mod 1000000007

using namespace std;

unordered_map<unsigned long long, unsigned long long> F;

unsigned long long fibonacci(unsigned long long n) {
    if (n == 0)
        return F[0];

    if (F[n])
        return F[n];
    
    if (n % 2 == 0) {
        F[n] = ((fibonacci(n / 2) % mod) * ((fibonacci(n / 2 + 1) % mod + fibonacci(n / 2 - 1) % mod) % mod)) % mod;
    }
    else {
        F[n] = ((((fibonacci((n + 1) / 2) % mod) * (fibonacci((n + 1) / 2) % mod)) % mod) + (((fibonacci((n - 1) / 2) % mod) * (fibonacci((n - 1) / 2) % mod)) % mod)) % mod;
    }

    return F[n];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    unsigned long long n;
    cin >> n;

    F[0] = 0;
    F[1] = F[2] = 1;

    cout << fibonacci(n) << endl;

    return 0;
}