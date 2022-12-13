#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int e_size = enemy.size();
    
    if (k >= e_size) {
        return e_size;
    }
    
    int start = 0;
    int end = e_size - 1;
    int mid = (start + end) / 2;

    priority_queue<int> pq;
    while (start <= end) {
        for (int i = 0; i <= mid; i++) {
            pq.push(enemy[i]);
        }
        
        // 무적권을 다 쓰고도 적들이 남아있음?
        // ㅇㅇ면 그 보다 더 적거나 같은 라운드 견디기 가능.
        if (pq.size() >= k) {
            for (int i = 0; i < k; i++) {
                pq.pop();
            }
            long long sum = 0;
            while (!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }
            
            // 무적권 다 쓰고 현재 병사 수가 남아있는 적들 수 보다 많으면 못 견딤.
            // = 버틸 수 있는 라운드가 줄어들어야함
            if (sum > n) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
                answer = max(answer, mid + 1);
            }
        }
        // ㄴㄴ면 더 많은 라운드 견디기 가능.
        else {
            while(!pq.empty()) {
                pq.pop();
            }
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    
    return answer;
}