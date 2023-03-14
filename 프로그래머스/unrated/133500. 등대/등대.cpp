#include <string>
#include <vector>
#include <queue>

using namespace std;

// 깊숙히 파고 들어서 각 서브트리에서 리프 노드를 가진 부모들의 등대를 켜주고,
// 켜줘야 하는 등대가 있는지 판별할거임. 그래서 dfs 사용.
void dfs(int node, vector<vector<int>>& ST, vector<bool>& light_on, int& answer, vector<bool>& visited) {
    visited[node] = true;
    bool is_on = false;
    for (int i = 0; i < ST[node].size(); i++) {
        int child = ST[node][i];
        if (visited[child])
            continue;
        
        dfs(child, ST, light_on, answer, visited);
        
        // 자식들 중에서 등대가 꺼진 곳이 있다면, 자신이 등대를 켜줄거임.
        if (!light_on[child]) {
            if (!is_on) {
                light_on[node] = true;
                answer++;
                is_on = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    vector<vector<int>> lights(n + 1);
    for (vector<int> house : lighthouse) {
        lights[house[0]].push_back(house[1]);
        lights[house[1]].push_back(house[0]);
    }

    // 1. 스패닝 트리를 먼저 찾아주자. (가중치 다 1로 똑같으니 BFS로 써봄) 이거 안해도 되나?
    // vector<vector<int>> ST(n + 1);
    vector<bool> visited(n + 1, false);
    /*queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int n = q.front();
        q.pop();

        for (int i = 0; i < lights[n].size(); i++) {
            if (!visited[lights[n][i]]) {
                visited[lights[n][i]] = true;
                ST[n].push_back(lights[n][i]);
                q.push(lights[n][i]);
            }
        }
    }*/

    // 2. DFS로 자식들의 등대 상태를 보고 자신이 켤지 말지 결정한다.
    vector<bool> light_on(n + 1, false);
    dfs(1, lights, light_on, answer, visited);
    //dfs(1, ST, light_on, answer);

    return answer;
}