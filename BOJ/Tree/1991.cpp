#include <iostream>
using namespace std;

struct Node {
    char left;
    char right;
} tree[25];

void preorder(char root) {
    if (root == '.') {
        return;
    }
    else {
        cout << root;
        preorder(tree[(int)(root-'A')].left);
        preorder(tree[(int)(root-'A')].right);
    }
}

void inorder(char root) {
    if (root == '.') {
        return;
    }
    else {
        inorder(tree[(int)(root-'A')].left);
        cout << root;
        inorder(tree[(int)(root-'A')].right);
    }
}

void postorder(char root) {
    if (root == '.') {
        return;
    }
    else {
        postorder(tree[(int)(root-'A')].left);
        postorder(tree[(int)(root-'A')].right);
        cout << root;
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char label, _left, _right;
        cin >> label >> _left >> _right;
        tree[(int)(label-'A')].left = _left;
        tree[(int)(label-'A')].right = _right;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    cout << "\n";

    return 0;
}
