#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N;
bool prime_nums[4000001];
long long prime_sum[4000001]; // 2부터 n까지 소수의 합

int get_next(int n) {
    for (int i = n + 1; i <= N; i++) {
        if (!prime_nums[i]) {
            return i;
        }
    }
    return N + 1;
}

int get_front(int n) {
    for (int i = n - 1; i >= 2; i--) {
        if (!prime_nums[i]) {
            return i;
        }
    }
    return 1;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    prime_nums[0] = true;
    prime_nums[1] = true;
    for (int i = 2; i * i <= N; i++) {
        if (!prime_nums[i]) {
            for (int j = i * i; j <= N; j += i) {
                prime_nums[j] = true;
            }
        }
    }

    long long sum = 0;
    for (int i = 2; i <= N; i++) {
        if (!prime_nums[i]) {
            sum += i;
            prime_sum[i] = sum;
        }
    }

    int left = 1;
    int right = 2;
    sum = 0;
    int answer = 0;
    while (left <= right && right <= N) {
        if (prime_sum[right] - prime_sum[left] > N) {
            left = get_next(left);
        }
        else {
            if (prime_sum[right] - prime_sum[left] == N) {
                answer++;
            }
            right = get_next(right);
        }
    }

    cout << answer << endl;

    return 0;
}