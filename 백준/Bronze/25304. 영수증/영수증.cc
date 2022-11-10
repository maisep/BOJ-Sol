#include <iostream>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a;
    cin >> b;
    
    int cost = 0;
    for (int i = 0; i < b; i++) {
        cin >> c >> d;
        cost += c * d;
    }
    if (a == cost)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}