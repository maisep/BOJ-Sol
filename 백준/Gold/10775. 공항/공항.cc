#include <iostream>
#include <vector>
#include <set>

#define endl '\n'

using namespace std;

int gates[100001];

int find_gate(int p) {
    if (gates[p] == p)
        return p;
    return gates[p] = find_gate(gates[p]);
}

void union_gate(int g1, int g2) {
    int a = find_gate(g1);
    int b = find_gate(g2);

    if (a != b)
        gates[b] = a;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int G;
    cin >> G;

    for (int i = 1; i <= G; i++)
        gates[i] = i;

    int P;
    cin >> P;

    vector<int> planes(P);
    for (int p = 0; p < P; p++) {
        cin >> planes[p];
    }

    int answer = 0;
    for (int plane : planes) {
        int g = find_gate(plane);

        if (g != 0) {
            union_gate(g - 1, g);
            answer++;
        }
        else {
            break;
        }
    }

    cout << answer << endl;

    return 0;
}