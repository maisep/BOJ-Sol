#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    b += a * 60;
    b += c;
    if (b >= 1440)
        b -= 1440;
    cout << (int)(b / 60) << " " << b % 60 << endl;
    
    return 0;
}