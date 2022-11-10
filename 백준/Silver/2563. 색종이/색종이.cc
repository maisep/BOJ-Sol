#include <iostream>
#include <string>

#define endl '\n'
using namespace std;

int paper[101][101];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int x, y;
    for (int n = 0; n < N; n++) {
        cin >> x >> y;

        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                paper[i][j] = 1;
            }
        }
    }

    int size = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (paper[i][j])
                size++;
        }
    }
    
    cout << size;

    return 0;
}