#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a == b && b == c) {
        cout << 10000 + 1000 * a << endl;
    }
    else if (a == b) {
        cout << 1000 + 100 * b;
    }
    else if (b == c) {
        cout << 1000 + 100 * b;
    }
    else if (a == c) {
        cout << 1000 + 100 * a;
    }
    else {
        cout << 100 * max(a, max(b, c)) << endl;
    }
    
    return 0;
}