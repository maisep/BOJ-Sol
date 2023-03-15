#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<long long, long long>> points;
    long long x, y;
    for (int n = 0; n < N; n++) {
        cin >> x >> y;
        points.push_back({ x, y });
    }

    long long xy = 0;
    long long yx = 0;
    for (int i = 0; i < N - 1; i++) {
        xy += points[i].first * points[i + 1].second;
        yx += points[i].second * points[i + 1].first;
    }
    xy += points[N - 1].first * points[0].second;
    yx += points[N - 1].second * points[0].first;

    double size = abs((xy - yx) / 2.0);

    cout << fixed;
    cout.precision(1);
    cout << size << endl;

    return 0;
}