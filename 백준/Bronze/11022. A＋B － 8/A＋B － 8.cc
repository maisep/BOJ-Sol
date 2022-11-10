#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    
    int a, b;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b;
        cout << "Case #" << i << ": " << a << " + " << b  << " = " << a + b << endl;
    }
    return 0;
}