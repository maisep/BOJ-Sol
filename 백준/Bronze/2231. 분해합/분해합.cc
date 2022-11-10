#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int answer = 987654321;

    for (int i = N - 1; i >= 0; i--) {
        int constructor = 0;
        int tmp = i;
        constructor = tmp;
        while (tmp > 0) {
            constructor += (tmp % 10);
            tmp /= 10;
        }

        if (constructor == N) {
            answer = min(answer, i);
        }
    }

    if (answer == 987654321) {
        cout << 0 << endl;
    }
    else {
        cout << answer << endl;
    }

    return 0;
}