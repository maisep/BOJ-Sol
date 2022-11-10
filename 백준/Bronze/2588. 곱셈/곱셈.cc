#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int result = a * b;
    cout << a * (b % 10) << endl;
    cout << a * (int)((b % 100) / 10) << endl;
    cout << a * (int)(b / 100) << endl;
    cout << result << endl;
    
    return 0;
}