#include <iostream>
using namespace std;
int main() {
    double mob, user;
    cin >> mob >> user;
    
    mob = mob - (mob * (user * 0.01));
    
    if (mob >= 100.0) {
        cout << 0;
    }
    else {
        cout << 1;
    }
    return 0;
}