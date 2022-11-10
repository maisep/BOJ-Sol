#include <iostream>
#include <string>
using namespace std;
int A[10001];
int B[10001];
int S[10001];
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    int max_len = (a.length() > b.length()) ? a.length() : b.length();

    for (int i = 0; i < a.length(); i++) {
        A[i] = a[a.length() - (i + 1)] - '0';
    }
    for (int i = 0; i < b.length(); i++) {
        B[i] = b[b.length() - (i + 1)] - '0';
    }
    for (int i = 0; i < max_len + 1; i++) {
        S[i] = A[i] + B[i] + S[i];
        
        if (S[i] >= 10) {
            S[i] -= 10;
            S[i + 1] = 1;
        }
    }

    if (S[max_len])
        cout << S[max_len];
    for (int i = max_len - 1; i >= 0; i--) {
        cout << S[i];
    }

    return 0;
}