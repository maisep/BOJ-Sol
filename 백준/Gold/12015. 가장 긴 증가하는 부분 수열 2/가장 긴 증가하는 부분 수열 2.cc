#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> LIS;
    LIS.push_back(A[0]);
    int len = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] > LIS[len]) {
            LIS.push_back(A[i]);
            len++;
        }
        else {
            vector<int>::iterator idx = lower_bound(LIS.begin(), LIS.end(), A[i]);
            *idx = A[i];
        }
    }

    cout << len + 1 << endl;

    return 0;
}
