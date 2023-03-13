#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

// 반환 값은 이진수를 역순으로 나열한 것임!
string get_bin(long long number) {
    string bin_num = "";
    while (number > 1) {
        bin_num += to_string(number % 2);
        number /= 2;
    }
    bin_num += to_string(number);
    return bin_num;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    string bin_num = "";

    for (long long number : numbers) {
        bool result = true;

        if (number == 1) {
            answer.push_back(1);
            continue;
        }
        // 1. 일단 numbers를 이진수로 바꾼다?
        bin_num = get_bin(number);

        // 2. 포화 이진트리니까 노드의 수는 2^n - 1개 만큼 있어야함. 
        // 즉, 비트 수가 2^n - 1개 만큼 필요하다는 뜻이니까, 0을 추가해준다.
        // 숫자가 최대 10^15 이므로, 노드의 수는 최대 63개(= 2^16)이다.
        int bin_len = bin_num.length();
        int bit = 1;
        int height;
        for (height = 0; height < 16; height++) {
            if (bin_len <= bit)
                break;
            bit *= 2;
        }

        int need = bit - bin_len;
        for (int i = 0; i < need; i++) {
            bin_num += "0";
        }

        // 3. (내가) 쉽게 풀 수 있도록 이진수를 역순으로 나열해준다. (안 해도 될거같음 ㅇㅇ)
        reverse(bin_num.begin(), bin_num.end());

        // 4. 부모 노드가 0이라면 표현 가능한 이진트리가 아니다!
        queue<pair<int, int>> q; // { 노드, level(그 노드가 몇 층에 있는지 ㅇㅇ) }
        q.push({ bin_num.length() / 2, height });
        while (!q.empty()) {
            int node = q.front().first;
            int level = q.front().second;
            q.pop();

            // 왼쪽 자식은 2^(현재 층 - 1) / 2 를 빼준 것, 오른쪽은 더한 것
            int n = pow(2, level - 1) / 2;
            int left = node - n;
            int right = node + n;
            // 부모가 0인데 자식에 1이 있다면? 표현 불가!
            if (bin_num[node] == '0') {
                if (bin_num[left] == '1' || bin_num[right] == '1') {
                    result = false;
                    answer.push_back(0);
                    break;
                }
            }

            // 최하단 층이면 자식이 없으므로 진행 안 해도 됨.
            if (level > 1) {
                q.push({ left, level - 1 });
                q.push({ right, level - 1 });
            }
        }

        if (result) {
            answer.push_back(1);
        }
    }

    return answer;
}