#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

vector<vector<char>> tree;

void preorder(char node) {
    if (node == '.')
        return;

    cout << node;
    preorder(tree[node - 65][0]);
    preorder(tree[node - 65][1]);
}

void inorder(char node) {
    if (node == '.')
        return;

    inorder(tree[node - 65][0]);
    cout << node;
    inorder(tree[node - 65][1]);
}

void postorder(char node) {
    if (node == '.')
        return;

    postorder(tree[node - 65][0]);
    postorder(tree[node - 65][1]);
    cout << node;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    tree.resize(N + 1); // 0번 인덱스 = 왼쪽 자식, 1번 인덱스 = 오른쪽 자식
    char a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;

        tree[a - 65].push_back(b);
        tree[a - 65].push_back(c);
    }

    preorder('A');
    cout << endl;
    inorder('A');
    cout << endl;
    postorder('A');
    cout << endl;

    return 0;
}

