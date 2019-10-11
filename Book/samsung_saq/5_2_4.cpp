#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int MAT[11][11];
bool check[11];
int answer;

void dfs(int idx, int sum, int cnt) {
    if (cnt == n) {
        if (MAT[idx][m] != 0) {
            if (answer == -1 || answer > sum + MAT[idx][m]) {
                answer = sum + MAT[idx][m];
            }
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (MAT[idx][i] != 0 && check[i] == false) {
                if (answer == -1 || answer > sum + MAT[idx][i]) {
                    check[idx] = true;
                    dfs(i, sum + MAT[idx][i], cnt + 1);
                    check[idx] = false;
                }
            }
        }
    }
}

int main() {
    int test_case;
    scanf_s("%d", &test_case);

    for (int t = 1; t <= test_case; t++) {
        scanf_s("%d %d", &n, &m);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                MAT[i][j] = 0;
            }
            check[i] = false;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf_s("%d", &MAT[i][j]);
            }
        }

        answer = -1;
        check[m] = true;
        dfs(m, 0, 1);

        printf("#%d %d\n", t, answer);
    }

    return 0;
}
