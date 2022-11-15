#include <iostream>

#define endl '\n'

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    int count = 0;
    while (A < B) {
        if (B % 2 == 0) {
            B /= 2;
            count++;
        }
        else {
            int tmp = B / 10;
            tmp = B - (tmp * 10);
            if (tmp == 1) {
                B /= 10;
                count++;
            }
            else {
                count = -2;
                break;
            }
        }
    }
    if (A > B)
        count = -2;
    
    cout << count + 1 << endl;

    return 0;
}

