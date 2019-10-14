#include <iostream>
using namespace std;

int arr[1001][1001];
bool check[1001];
int n, m, solution;

void dfs(int x, int solution) {
    check[x] = true;
    for (int i = 1; i <= n; i++) {
        if (arr[x][i] == 1 && check[i] == false) {
            dfs(i, solution);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        arr[u][v] = 1; arr[v][u] = 1;
    }

    solution = 0;
    for (int i = 1; i <= n; i++) {
        if (check[i] == false) {
            solution++;
            dfs(i, solution);
        }
    }

    printf("%d\n", solution);

    return 0;
}
