#include <iostream>
#include <unordered_map>
#include <vector>

#define endl '\n'

using namespace std;

int tree[1000000][2];

void input_node(int root, int &data) {
    // 루트보다 크면 오른쪽 자식으로, 작으면 왼쪽 자식이다.
    if (data > root) {
        if (tree[root][1] == 0) {
            tree[root][1] = data;
        }
        else {
            input_node(tree[root][1], data);
        }
    }
    else {
        if (tree[root][0] == 0) {
            tree[root][0] = data;
        }
        else {
            input_node(tree[root][0], data);
        }
    }
}

void postorder(int root) {
    if (root == 0) {
        return;
    }
    else {
        postorder(tree[root][0]);
        postorder(tree[root][1]);
        cout << root << endl;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int node;
    cin >> node;
    int root = node;
    cin >> node;
    while (!cin.eof()) {
        input_node(root, node);
        cin >> node;
    }
    
    postorder(root);

    return 0;
}

