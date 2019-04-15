#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10000 + 1;

pair<int, int> Tree[MAX];
int root[MAX];
int low[MAX];
int high[MAX];

int idx = 1;

void inOrder(int node, int count) {

    if (Tree[node].first > 0) {
        inOrder(Tree[node].first, count + 1);
    }

    low[count] = min(low[count], idx);
    high[count] = max(high[count], idx++);

    if (Tree[node].second > 0) {
        inOrder(Tree[node].second, count + 1);
    }
}

int main() {
    int nCase, r, result, level;
    cin >> nCase;

    for (int i = 0; i < MAX; i++) {
        low[i] = 987654321;
    }

    for (int i = 0; i < nCase; i++) {
        int parent, left, right;
        cin >> parent >> left >> right;
        root[parent]++;

        if (left != -1) {
            root[left]++; 
        }
        Tree[parent].first = left;

        if (right != -1) {
            root[right]++;
        }
        Tree[parent].second = right;
    }

    for (int i = 1; i <= nCase; i++) {
        if (root[i] == 1) {
            r = i;
        }
    }

    inOrder(r, 1);

    result = high[1] - low[1] + 1;
    level = 1;
    for (int i = 2; i <= nCase; i++) {
        int temp = high[i] - low[i] + 1;
        if (temp > result) {
            result = temp;
            level = i;
        }
    }

    cout << level << " " << result << "\n";

    return 0;
}
