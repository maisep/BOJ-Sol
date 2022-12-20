#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    int NM = N + M;

    vector<int> A;
    int a;
    for (int i = 0; i < NM; i++) {
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());

    for (int i = 0; i < NM; i++) {
        cout << A[i] << " ";
    }

    return 0;
}