#include <iostream>
#include <string>

#define endl '\n'
using namespace std;

int num[80];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string result;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> result;

        bool check = false;
        int s = 1;
        int score = 0;
        for (int j = 0; j < result.length(); j++) {
            if (result[j] == 'O') {
                if (check) {
                    s++;
                }
                check = true;
                score += s;
            }
            else {
                check = false;
                s = 1;
            }
        }
        cout << score << endl;
    }

    return 0;
}