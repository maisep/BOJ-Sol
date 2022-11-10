#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    int M;
    cin >> N >> M;

    vector<int> cards(N, 0);
    vector<int> comb(N, 0);
    comb[N - 1] = 1;
    comb[N - 2] = 1;
    comb[N - 3] = 1;
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    int answer = 0;

    do {
        int sum = 0;

        for (int i = 0; i < N; i++) {
            if (comb[i] == 1) {
                sum += cards[i];
            }
        }
        if (sum <= M) {
            answer = max(answer, sum);
        }
    } while (next_permutation(comb.begin(), comb.end()));

    cout << answer << endl;

    return 0;
}