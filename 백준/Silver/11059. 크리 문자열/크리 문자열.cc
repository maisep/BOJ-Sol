#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    int S_Len = S.length();
    int KRI_LEN = (S_Len % 2 == 1) ? S_Len - 1 : S_Len;
    int left_sum = 0;
    int right_sum = 0;
    bool is_find = false;
    while (KRI_LEN > 2 && !is_find) {
        for (int i = 0; i <= S_Len - KRI_LEN && !is_find; i++) {
            left_sum = 0;
            right_sum = 0;
            for (int j = i; j < i + KRI_LEN / 2; j++) {
                left_sum += (S[j] - '0');
                right_sum += (S[j + KRI_LEN / 2] - '0');
            }
            if (left_sum == right_sum) {
                is_find = true;
            }
        }
        if (!is_find) {
            KRI_LEN -= 2;
        }
    }

    cout << KRI_LEN << endl;

    return 0;
}