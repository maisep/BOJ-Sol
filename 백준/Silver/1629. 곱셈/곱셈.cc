#include <iostream>

#define endl '\n'

using namespace std;

int mul(int A, int B, int C) {
    if (B > 1) {
        long long result = mul (A, B / 2, C);

        if (B % 2) 
            return ((result * result) % C * A) % C;
        else 
            return (result * result) % C;
    }
    else 
        return A;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;

    int answer = mul(A % C, B, C);
    
    cout << answer << endl;
    return 0;
}