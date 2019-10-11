#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int portal[3001];
int answer;

void dfs(int x, int cnt) {
    if (x == m) {
        answer = max(answer, cnt);
    }
    else {
        if (portal[x] <= m) {
            dfs(portal[x], cnt + 1);
        }
    }
}

int main() {
    int test_case;
    scanf_s("%d", &test_case);

    for (int t = 1; t <= test_case; t++) {
        scanf_s("%d %d", &n, &m);

        for (int i = 1; i <= n - 1; i++) {
            scanf_s("%d", &portal[i]);
        }

        answer = -1;

        for (int i = 1; i < m; i++) {
            dfs(i, 0);
        }

        printf("#%d %d\n", t, answer);
    }

    return 0;
}
