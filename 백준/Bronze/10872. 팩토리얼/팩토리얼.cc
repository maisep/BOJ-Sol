#include <iostream>
#include <string>

using namespace std;

int alp[26];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int f = 1;
    for (int i = n; i > 0; i--)
        f *= i;

    cout << f << endl;
    return 0;
}