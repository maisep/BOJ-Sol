#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int a, b;
    cin >> a >> b;
    while (!cin.eof()) {
        cout << a + b << '\n';
        cin >> a >> b;
    }
    return 0;
}