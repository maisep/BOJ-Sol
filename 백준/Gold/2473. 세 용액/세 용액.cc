#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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

    sort(L.begin(), L.end());

    long long min_s = -9876543210;

    int val[3] = { 0, 0, 0 };

    long long s;

    for (int i = 0; i < N - 2; i++) {
        int front = i + 1;
        int back = N - 1;
        while (front < back) {
            s = (long long)L[i] + (long long)L[front] + (long long)L[back];
            if (abs(min_s) > abs(s)) {
                min_s = s;
                val[0] = L[i];
                val[1] = L[front];
                val[2] = L[back];
            }

            if (s >= 0) {
                back--;
            }
            else {
                front++;
            }
        }
    }

    cout << val[0] << " " << val[1] << " " << val[2];

    return 0;
}