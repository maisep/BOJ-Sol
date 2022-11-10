#include <cstdio>

int num[9];
int N, M;

void dfs(int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", num[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		num[count] = i;
		dfs(count + 1);
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		num[i] = i;
	}

	scanf("%d %d", &N, &M);
	
	dfs(0);

	return 0;
}