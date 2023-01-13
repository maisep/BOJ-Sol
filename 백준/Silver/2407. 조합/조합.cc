#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

string answer[101][101];

string add(string a, string b) {
    string num = "";
    int sum = 0;
    int max_len = max(a.size(), b.size());

    for (int i = 0; i < max_len || sum; i++) {
        if (a.size() > i)
            sum += a[i] - '0';
        if (b.size() > i)
            sum += b[i] - '0';  
        num += sum % 10 + '0';
        sum /= 10;
    }

    return num;
}

string comb(int n, int m) {
    if (n == m || m == 0) 
        return "1";

    if (answer[n][m] != "")
        return answer[n][m];

    answer[n][m] = add(comb(n - 1, m - 1), comb(n - 1, m));

    return answer[n][m];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    comb(n, m);

    for (int i = answer[n][m].size() - 1; i >= 0; i--)
        cout << answer[n][m][i];

    return 0;
}