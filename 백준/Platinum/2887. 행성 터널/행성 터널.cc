#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

#define endl '\n'

using namespace std;

vector<pair<int, int>> planet_tunnels[100000];
bool visited[100000];

bool cmp_x(vector<int>& a, vector<int>& b) {
    if (a[1] != b[1])
        return a[1] < b[1];
    else if (a[2] != b[2])
        return a[2] < b[2];
    else if (a[3] != b[3])
        return a[3] < b[3];
    else
        return a[0] < b[0];
}

bool cmp_y(vector<int>& a, vector<int>& b) {
    if (a[2] != b[2])
        return a[2] < b[2];
    else if (a[3] != b[3])
        return a[3] < b[3];
    else if (a[1] != b[1])
        return a[1] < b[1];
    else
        return a[0] < b[0];
}

bool cmp_z(vector<int>& a, vector<int>& b) {
    if (a[3] != b[3])
        return a[3] < b[3];
    else if (a[1] != b[1])
        return a[1] < b[1];
    else if (a[2] != b[2])
        return a[2] < b[2];
    else
        return a[0] < b[0];
}

int get_cost(vector<int>& a, vector<int>& b) {
    return min(abs(a[1] - b[1]), min(abs(a[2] - b[2]), abs(a[3] - b[3])));
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int>> planets(N, vector<int>(4)); // num, x, y, z
    for (int n = 0; n < N; n++) {
        planets[n][0] = n;
        cin >> planets[n][1] >> planets[n][2] >> planets[n][3];
    }

    sort(planets.begin(), planets.end(), cmp_x); // sort_x
    for (int i = 0; i < N - 1; i++) {
        int to = planets[i][0];
        int from = planets[i + 1][0];
        int cost = get_cost(planets[i], planets[i + 1]);
        planet_tunnels[to].push_back({ cost, from });
        planet_tunnels[from].push_back({ cost, to });
    }
    
    sort(planets.begin(), planets.end(), cmp_y); // sort_y
    for (int i = 0; i < N - 1; i++) {
        int to = planets[i][0];
        int from = planets[i + 1][0];
        int cost = get_cost(planets[i], planets[i + 1]);
        planet_tunnels[to].push_back({ cost, from });
        planet_tunnels[from].push_back({ cost, to });
    }

    sort(planets.begin(), planets.end(), cmp_z); // sort_z
    for (int i = 0; i < N - 1; i++) {
        int to = planets[i][0];
        int from = planets[i + 1][0];
        int cost = get_cost(planets[i], planets[i + 1]);
        planet_tunnels[to].push_back({ cost, from });
        planet_tunnels[from].push_back({ cost, to });
    }

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, 0 });

    unsigned long long answer = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int planet = pq.top().second;
        pq.pop();

        if (visited[planet])
            continue;

        visited[planet] = true;
        answer += cost;

        for (int i = 0; i < planet_tunnels[planet].size(); i++) {
            int next_cost = planet_tunnels[planet][i].first;
            int next_planet = planet_tunnels[planet][i].second;
            if (!visited[next_planet]) {
                pq.push({ -next_cost, next_planet });
            }
        }
    }

    cout << answer << endl;

    return 0;
}