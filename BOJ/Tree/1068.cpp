#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Tree {
    int val;
    int parent;
    vector<int> child;
} tree[50];


int calc(int start) {
    int count = 0;
    queue<int> q;

    q.push(start);

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        if (tree[here].child.empty()) {
            count++;
        }

        for (unsigned int i = 0; i < tree[here].child.size(); i++) {
            q.push(tree[here].child[i]);
        }
    }

    return count;
}

int main() {
    int N, start, del;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tree[i].val;

        if (tree[i].val == -1) {
            start = i;
        }
        else {
            int p = tree[i].val;
            int c = i;
            tree[c].parent = p;
            tree[p].child.push_back(c);
        }
    }

    cin >> del;

    if (del == start) {
        cout << "0\n";
    }
    tree[del].child.clear();

    int p = tree[del].parent;
    for (unsigned int i = 0; i < tree[p].child.size(); i++) {
        if (tree[p].child[i] == del) {
            tree[p].child.erase(tree[p].child.begin() + i);
        }
    }

    cout << calc(start) << "\n";

    return 0;
}
