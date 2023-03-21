#include <string>
#include <vector>

using namespace std;

int C[5000001];
int MAX_COUNT[5000001];

void count_fact(int e) {
    for (long long i = 1; i <= e; i++) {
        for (long long j = 1; j <= e && i * j <= e; j++) {
            C[i * j]++;
        }
    }
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;

    count_fact(e);

    int max_cnt = 0;
    int min_num = 5000001;
    for (int i = e; i > 0; i--) {
        if (max_cnt <= C[i]) {
            max_cnt = C[i];
            MAX_COUNT[i] = i;
            min_num = i;
        }
        else {
            MAX_COUNT[i] = min_num;
        }
    }

    for (int s : starts) {
        answer.push_back(MAX_COUNT[s]);
    }

    return answer;
}