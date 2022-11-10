#include <cstdio>

int num[9];
bool visited[9];
int N, M;

void dfs(int count, int n) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", num[i]);
		}
		printf("\n");
	}

	for (int i = n; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			num[count] = i;
			dfs(count + 1, i);
			visited[i] = false;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		num[i] = i;
	}

	scanf("%d %d", &N, &M);
	
	dfs(0, 1);

	return 0;
}