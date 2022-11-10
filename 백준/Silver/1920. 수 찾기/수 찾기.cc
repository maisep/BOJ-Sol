#include <cstdio>
#include <algorithm>

int A[100000];
int N, M;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	
	std::sort(A, A + N);

	scanf("%d",&M);

	int find;
	for (int i = 0; i < M; i++) {
		scanf("%d", &find);
		printf("%d\n", std::binary_search(A, A + N, find));
	}
	
	return 0;
}