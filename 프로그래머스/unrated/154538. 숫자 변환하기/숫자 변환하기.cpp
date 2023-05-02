#include <string>
#include <vector>

using namespace std;

const int INF = 1234567890;
int dp[1000001];

void dfs(int x, int y, int n) {
    if (y % 3 == 0 && y / 3 >= x) {
        if (dp[y / 3] > dp[y] + 1) {
            dp[y / 3] = dp[y] + 1;
            dfs(x, y / 3, n);
        }
    }
    
    if (y % 2 == 0 && y / 2 >= x) {
        if (dp[y / 2] > dp[y] + 1) {
            dp[y / 2] = dp[y] + 1;
            dfs(x, y / 2, n);
        }
    }
    
    if (y - n >= x) {
        if (dp[y - n] > dp[y] + 1) {
            dp[y - n] = dp[y] + 1;
            dfs(x, y - n, n);
        }
    }
}

int solution(int x, int y, int n) {
    int answer = 0;
    
    dp[y] = 0;
    for (int i = 1; i < y; i++) {
        dp[i] = INF;
    }
    
    dfs(x, y, n);
    
    answer = dp[x];
    if (answer == INF)
        answer = -1;
    
    return answer;
}