#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int X[1000001];
set<int> s;
map<int, int> xi;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> X[i];
        s.insert(X[i]);
    }

    int o = 0;
    for (int a : s) {
        xi[a] = o;
        ++o;
    }

    for (int i = 0; i < N; ++i) {
        cout << xi[X[i]] << " ";
    }

    return 0;
}