#include <iostream>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    if (x < 0)
        if (y < 0)
            cout << 3 << endl;
        else
            cout << 2 << endl;
    else
        if (y < 0)
            cout << 4 << endl;
        else
            cout << 1 << endl;
    
    return 0;
}