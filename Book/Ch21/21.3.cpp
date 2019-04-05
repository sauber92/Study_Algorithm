#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sliceVector(vector<int> vec, int begin, int end) {
    vector<int> tmp(vec.begin() + begin, vec.begin() + end);
    return tmp;
}

void printPostOrder(vector<int> preorder,
                    vector<int> inorder) {
    int root = preorder.front();

    int size = preorder.size();
    int left_size = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    int right_size = size - 1 - left_size;

    if (size == 0) {
        return;
    }

    printPostOrder(sliceVector(preorder, 1, left_size+1),
                   sliceVector(inorder, 0, left_size)) ;
    printPostOrder(sliceVector(preorder, left_size+1, size),
                   sliceVector(inorder, left_size+1, size));
    cout << root << " ";
}

int main() {
    int nCase, nNode, pre, in;

    cin >> nCase >> nNode;

    for (int i = 0; i < nCase; i++) {
        vector<int> preorder, inorder;

        for (int j = 0; j < nNode; j++) {
            cin >> pre;
            preorder.push_back(pre);
        }
        for (int j = 0; j < nNode; j++) {
            cin >> in;
            inorder.push_back(in);

        }

        printPostOrder(preorder, inorder);
        cout << "\n";
    }

    return 0;
}
