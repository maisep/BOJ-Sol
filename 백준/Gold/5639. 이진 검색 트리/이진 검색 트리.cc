#include <iostream>
#include <unordered_map>
#include <vector>

#define endl '\n'

using namespace std;

int left_node[1000000];
int right_node[1000000];

void input_node(int root, int &data) {
    // 루트보다 크면 오른쪽 자식으로, 작으면 왼쪽 자식이다.
    if (data > root) {
        if (right_node[root] == 0) {
            right_node[root] = data;
        }
        else {
            input_node(right_node[root], data);
        }
    }
    else {
        if (left_node[root] == 0) {
            left_node[root] = data;
        }
        else {
            input_node(left_node[root], data);
        }
    }
}

void postorder(int root) {
    if (root == 0) {
        return;
    }
    else {
        postorder(left_node[root]);
        postorder(right_node[root]);
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

