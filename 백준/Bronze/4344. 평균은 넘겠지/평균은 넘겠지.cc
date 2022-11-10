#include <iostream>
#include <string>

#define endl '\n'
using namespace std;

double num[1000];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int C;
    cin >> C;

    for (int i = 0; i < C; i++) {
        int N;
        cin >> N;
        double sum = 0;
        for (int j = 0; j < N; j++) {
            cin >> num[j];
            sum += num[j];
        }
        sum = sum / N;
        double count = 0;
        for (int j = 0; j < N; j++) {
            if (num[j] > sum) {
                count++;
            }
        }
        count = count / N * 100;
        cout << fixed;
        cout.precision(3);
        cout << count << "%" << endl;
    }

    return 0;
}