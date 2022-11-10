#include <cstdio>
#include <algorithm>

int card[500000];
int N, M;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &card[i]);
	}

	std::sort(card, card + N);

	scanf("%d", &M);

	int find;
	for (int i = 0; i < M; i++) {
		scanf("%d", &find);
		printf("%d ", std::upper_bound(card, card + N, find) - std::lower_bound(card, card + N, find));
	}


	return 0;
}