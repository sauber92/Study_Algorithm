#include <iostream>
using namespace std;

class Node {
    int data;
    Node* left;
    Node* right;
    public:
    Node(int _data) {
        this->data = _data; 
        this->left = NULL;
        this->right = NULL;
    }
    ~Node() {
        delete left;
        delete right;
    }
    int getData() { return data; }
    Node* getLeft() { return left; }
    Node* getRight() { return right; }
    void setLeft(Node* _left) { this->left = _left; }
    void setRight(Node* _right) { this->right = _right; }
};

class Tree {
    Node* root;
    public:
    Tree() { root = NULL; }
    ~Tree() { delete root; }
    Node* getRoot() { return root; }
    void insertNode(int newdata);
    void postOrder(Node* root);
};

void Tree::insertNode(int newdata) {
    Node* tmp;
    Node* compare;
    tmp = NULL;
    compare = this->root;

    while (compare != NULL) {
        tmp = compare;
        if (newdata < tmp->getData()) {
            compare = tmp->getLeft();
        }
        else {
            compare = tmp->getRight();
        }
    }

    Node* newnode = new Node(newdata);
    if (tmp == NULL) {
        this->root = newnode;
    }
    else if (newdata < tmp->getData()) {
        tmp->setLeft(newnode);
    }
    else {
        tmp->setRight(newnode);
    }
}

void Tree::postOrder(Node* root) {
    if (root) {
        postOrder(root->getLeft());
        postOrder(root->getRight());
        cout << root->getData() << "\n";
    }
}

int main() {
    int value;
    Tree* t = new Tree;

    while (scanf("%d", &value) != EOF) {
        t->insertNode(value);
    }

    t->postOrder(t->getRoot());

    delete t;

    return 0;
}
