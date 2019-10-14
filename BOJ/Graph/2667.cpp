#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[25][25];
int check[25][25];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y, int component) {
    check[x][y] = component;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (map[nx][ny] == 1 && check[nx][ny] == 0) {
                dfs(nx, ny, component);
            }
        }
    }
}

int main() {
    int component;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    component = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && check[i][j] == 0) {
                dfs(i, j, ++component);
            }
        }
    }

    printf("%d\n", component);

    vector<int> ans;
    int tmp = 0;
    for (int k = 1; k <= component; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (check[i][j] == k) {
                    tmp++;
                }
            }
        }
        ans.push_back(tmp);
        tmp = 0;
    }

    sort(ans.begin(), ans.end());
    for (auto itr = ans.begin(); itr != ans.end(); itr++) {
        printf("%d\n", *itr);
    }

    return 0;
}
