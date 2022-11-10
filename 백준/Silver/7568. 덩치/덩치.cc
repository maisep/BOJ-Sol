#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> H(N, vector<int>(3, 0));
    for (int i = 0; i < N; i++) {
        cin >> H[i][0] >> H[i][1];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (H[i][0] < H[j][0] && H[i][1] < H[j][1]) {
                H[i][2]++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << H[i][2] + 1 << " ";
    }
    cout << endl;

    return 0;
}