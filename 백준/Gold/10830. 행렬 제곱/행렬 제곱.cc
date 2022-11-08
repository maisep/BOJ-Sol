#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N;
long long B;
vector<vector<short>> I;

vector<vector<short>> cal(vector<vector<short>> &a, vector<vector<short>> &b) {
    vector<vector<short>> c(N, vector<short>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % 1000;
            }
            c[i][j] %= 1000;
        }
    }

    return c;
}

vector<vector<short>> part(vector<vector<short>> &a, long long n) {
    if (n == 2) {
        return cal(a, a);
    }

    if (n % 2 == 1) {
        vector<vector<short>> p = part(a, n - 1);
        return cal(a , p);
    }
    else {
        vector<vector<short>> p = part(a, n / 2);
        return cal(p, p);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> B;

    vector<vector<short>> im(N, vector<short>(N));

    for (int i = 0; i < N; i++) {
        im[i][i] = 1;
    }

    I = im;

    vector<vector<short>> a(N, vector<short>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<short>> answer(N, vector<short>(N));
    if (B == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                answer[i][j] = a[i][j] % 1000;
            }
        }
    }
    else {
        answer = part(a, B);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
