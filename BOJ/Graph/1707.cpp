#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int> > vec(20001);
int check[20001]; // 0: not visited, 1: group A, 2: group B

void dfs(int idx, int c) {
    check[idx] = c;
    for (unsigned int i = 0; i < vec[idx].size(); i++) {
        int next = vec[idx][i];
        if (check[next] == 0) {
            dfs(next, 3-c);
        }
    }
}

int main() {
    int test_case;
    scanf("%d", &test_case);

    for (int t = 1; t <= test_case; t++) {
        int v, e;
        scanf("%d %d", &v, &e);

        for (int i = 1; i <= v; i++) {
            vec[i].clear();
            check[i] = 0;
        }

        for (int i = 1; i <= e; i++) {
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            vec[n1].push_back(n2);
            vec[n2].push_back(n1);
        }

        for (int i = 1; i <= v; i++) {
            if (check[i] == 0) {
                dfs(i, 1);
            }
        }

        bool solution = true;
        for (int i = 1; i <= v; i++) {
            for (int j = 0; j < vec[i].size(); j++) {
                int cur = vec[i][j];
                if (check[i] == check[cur]) {
                    solution = false;
                }
            }
        }
        printf("%s\n", solution ? "YES" : "NO");
    }

    return 0;
}
