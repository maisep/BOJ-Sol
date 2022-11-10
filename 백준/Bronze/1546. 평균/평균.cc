#include <iostream>

using namespace std;

double num[1000];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int max_s = -1999999999;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
        if (max_s < num[i])
            max_s = num[i];
    }

    double sum = 0;
    for (int i = 0; i < N; i++) {
        num[i] = num[i] / max_s * 100;
        sum += num[i];
    }

    sum /= N;

    cout << sum;

    return 0;
}