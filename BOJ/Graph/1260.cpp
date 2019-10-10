#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
    
vector<vector<int> > vec(1001);
bool check[1001];
queue<int> q;

void dfs(int x) {
    check[x] = true;
    printf("%d ", x);

    for (unsigned int i = 0; i < vec[x].size(); i++) {
        int y = vec[x][i];
        if (check[y] == false) {
            dfs(y);
        }
    }
}

void bfs(int x) {
    check[x] = true;
    q.push(x);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        printf("%d ", cur);

        for (unsigned int i = 0; i < vec[cur].size(); i++) {
            int y = vec[cur][i];
            if (check[y] == false) {
                check[y] = true;
                q.push(y);
            }
        }
    }
}

int main() {
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(vec[i].begin(), vec[i].end());
    }

    dfs(v);
    printf("\n");

    for (int i = 0; i <= n; i++) {
        check[i] = false;
    }

    bfs(v);
    printf("\n");

    return 0;
}
