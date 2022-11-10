#include <iostream>
#include <string>

#define endl '\n'
using namespace std;

int m1[9][9];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num = 0;
    int max_num = -1;
    int max_idx_x = -1;
    int max_idx_y = -1;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> m1[i][j];
            if (max_num < m1[i][j]) {
                max_num = m1[i][j];
                max_idx_x = i;
                max_idx_y = j;
            }
        }
    }

    cout << max_num << endl;
    cout << max_idx_x + 1 << " " << max_idx_y + 1;

    return 0;
}