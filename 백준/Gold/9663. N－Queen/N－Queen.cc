#include <iostream>

using namespace std;

int pos[14];
int q_count = 0;

void N_Queen(int p, int N) {
    if (p == N) {
        q_count++;

        return;
    }

    for (int i = 0; i < N; i++) {
        bool check = true;
        for (int j = 0; j < p; j++) {
            int left = pos[j] - (p - j);
            int right = pos[j] + (p - j);

            if ((left < 0 || i != left) && (right >= N || i != right) && (i != pos[j])) {
                continue;
            }

            check = false;
            break;
        }

        if (check) {
            pos[p] = i;
            N_Queen(p + 1, N);
        }
    }
}

int main() {
    int N;
    cin >> N;

    N_Queen(0, N);
    cout << q_count << endl;
    
    return 0;
}