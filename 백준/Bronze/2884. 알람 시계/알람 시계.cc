#include <iostream>
using namespace std;
int main() {
    int h, m;
    cin >> h >> m;
    m += h * 60;
    m -= 45;
    if (m < 0)
        m += 1440;
    cout << (int)(m / 60) << " " << m % 60 << endl;
    
    return 0;
}