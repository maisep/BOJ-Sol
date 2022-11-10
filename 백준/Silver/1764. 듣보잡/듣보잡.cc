#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string deudbojab[500000];

int main() {
	int N, M;
	map<string, int> deud;
	int count = 0;

	cin >> N >> M;

	string human = "";
	for (int i = 0; i < N; i++) {
		cin >> human;
		deud[human] = 1;
	}

	for (int i = 0; i < M; i++) {
		cin >> human;
		deud[human]++;
		if (deud[human] == 2) {
			deudbojab[count] = human;
			count++;
		}
	}

	sort(deudbojab, deudbojab + count);

	cout << count << endl;
	for (int i = 0; i < count; i++) {
		cout << deudbojab[i] << endl;
	}

	return 0;
}