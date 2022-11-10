#include <iostream>
#include <string>

using namespace std;

int alp[26];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    int o = 0;
    for (int i = 0; i < S.length(); i++) {
        if (!alp[S[i] - 'a'])
            alp[S[i] - 'a'] = i + 1;
    }

    for (int i = 0; i < 26; i++) {
        if (!alp[i]) {
            cout << -1 << " ";
        }
        else {
            cout << alp[i] - 1 << " ";
        }
    }

    return 0;
}