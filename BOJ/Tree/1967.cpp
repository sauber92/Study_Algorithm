#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 10000 + 1;
bool visited[MAX];
vector<pair<int, int> > tree[MAX];

int diameter = 0;
int farthestNode = 0;

void DFS(int node, int cost) {
    if (visited[node]) {
        return;
    }
    visited[node] = true;

    if (diameter < cost) {
        diameter = cost;
        farthestNode = node;
    }

    for (unsigned int i = 0; i < tree[node].size(); i++) {
        DFS(tree[node][i].first, cost + tree[node][i].second);
    }
}

int main() {
    int nNode;

    cin >> nNode;

    for (int i = 1; i < nNode; i++) {
        int node1, node2, cost;
        cin >> node1 >> node2 >> cost;

        tree[node1].push_back(make_pair(node2, cost));
        tree[node2].push_back(make_pair(node1, cost));
    }

    memset(visited, false, sizeof(visited));
    DFS(1, 0);

    memset(visited, false, sizeof(visited));
    diameter = 0;
    DFS(farthestNode, 0);

    cout << diameter << "\n";

    return 0;
}
