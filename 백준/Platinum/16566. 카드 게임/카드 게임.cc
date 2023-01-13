#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define endl '\n'

using namespace std;

vector<int> Minsu;
vector<int> Cheolsu;
vector<int> Minsu_Card;

int find(int a) {
    if (a == Minsu_Card[a])
        return a;
    else
        return find(Minsu_Card[a]);
}

void set_card(int pos) {
    int a = find(pos);
    int b = find(pos + 1);

    if (a != b) {
        Minsu_Card[a] = b;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;
    
    int a;
    for (int i = 0; i < M; i++) {
        cin >> a;
        Minsu.push_back(a);
        Minsu_Card.push_back(i);
    }
    Minsu_Card.push_back(Minsu_Card.size());

    for (int i = 0; i < K; i++) {
        cin >> a;
        Cheolsu.push_back(a);
    }

    sort(Minsu.begin(), Minsu.end());

    int pos;
    for (int card : Cheolsu) {
        pos = find(upper_bound(Minsu.begin(), Minsu.end(), card) - Minsu.begin());
        cout << Minsu[pos] << endl;
        set_card(pos);
    }

    return 0;
}