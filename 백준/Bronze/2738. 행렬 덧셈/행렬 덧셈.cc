#include <iostream>
#include <string>

#define endl '\n'
using namespace std;

int m1[100][100];
int m2[100][100];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> m1[i][j];
        }
    }

    int num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> num;
            m1[i][j] += num;
            cout << m1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}