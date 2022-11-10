#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dp[1001][1001];

int main() {
    string str1 = "";
    string str2 = "";

    cin >> str1;
    cin >> str2;

    int s1 = str1.length();
    int s2 = str2.length();

    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[s1][s2] << endl;

    return 0;
}