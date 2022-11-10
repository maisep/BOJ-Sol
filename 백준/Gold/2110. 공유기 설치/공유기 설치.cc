#include <iostream>
#include <algorithm>

using namespace std;

int house[200001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, C;
    cin >> N >> C;


    int h;
    for (int i = 0; i < N; i++) {
        cin >> h;
        house[i] = h;
    }

    sort(house, house + N);

    int left = 0;
    int right = house[N - 1];
    int mid = (left + right) / 2;
    int answer = 0;

    while (left <= right) {
        int h = house[0];
        int count = 1;
        
        for (int i = 1; i < N; i++) {
            if (house[i] - h >= mid) {
                count++;
                h = house[i];
            }
        }

        if (count >= C) {
            left = mid + 1;
            answer = max(answer, mid);
        }
        else {
            right = mid - 1;
        }

        mid = (left + right) / 2;
    }

    cout << answer << endl;

    return 0;
}


