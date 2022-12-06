#include <iostream>
#include <vector>

#define endl '\n'
#define INF 1987654321

using namespace std;

vector<vector<int>> cities(101, vector<int>(101, INF));

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int m;
    cin >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        cities[a][b] = min(c, cities[a][b]);
    }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (cities[j][i] != INF && cities[i][k] != INF)
                    cities[j][k] = min(cities[j][k], cities[j][i] + cities[i][k]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || cities[i][j] == INF)
                cout << 0 << " ";
            else
                cout << cities[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}