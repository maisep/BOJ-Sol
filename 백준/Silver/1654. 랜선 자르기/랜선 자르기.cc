#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K, N;
    cin >> K >> N;

    vector<int> lan(K);
    int max_len = 0;
    for (int i = 0; i < K; i++) {
        cin >> lan[i];
        max_len = max(max_len, lan[i]);
    }

    long long left = 1;
    long long right = max_len;
    long long mid = (left + right) / 2;
    long long answer = 0;

    while (left <= right) {
        int count = 0;
        for (int i = 0; i < K; i++) {
            count += lan[i] / mid;
        }

        // mid만큼 크기로 잘랐을 때 랜선의 수가 N보다 크거나 같으면
        // 자를 크기를 더 늘려줘야 한다.
        if (count >= N) {
            left = mid + 1;
            //answer = max(answer, mid);
        }
        // mid만큼 크기로 잘랐을 때 랜선의 수가 N보다 작다면
        // 자를 크기를 더 줄여줘야 한다.
        else {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }

    //cout << answer << endl;
    cout << mid << endl;

    return 0;
}