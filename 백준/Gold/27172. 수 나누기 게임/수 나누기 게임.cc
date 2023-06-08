#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

int players[100000]; // 참가자가 받은 카드 번호
bool cards[1000001]; // 해당 번호의 카드가 있는지
int point[1000001]; // 그 카드 번호로는 몇 점인지

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> players[i];
        cards[players[i]] = true;
    }

    for (int i = 0; i < N; i++) {
        int card = players[i];

        for (int j = 2; j * card < 1000001; j++) {
            if (cards[j * card]) {
                point[j * card]--;
                point[card]++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << point[players[i]] << " ";
    }

    return 0;
}