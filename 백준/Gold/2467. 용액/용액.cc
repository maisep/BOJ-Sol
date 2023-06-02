#include <iostream>
#include <vector>
#include <cmath>

#define endl '\n'

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> L;

    int l;
    for (int i = 0; i < N; i++) {
        cin >> l;
        L.push_back(l);
    }

    int min_s = -2000000001;

    int val[2] = { 0, 0 };

    int s;

    int front = 0;
    int back = N - 1;
    while (front < back) {
        s = L[front] + L[back];
        if (abs(min_s) > abs(s)) {
            min_s = s;
            val[0] = L[front];
            val[1] = L[back];
        }

        if (s >= 0) {
            back--;
        }
        else {
            front++;
        }
    }

    cout << val[0] << " " << val[1];

    return 0;
}