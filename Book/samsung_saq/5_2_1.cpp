#include <iostream>
#include <vector>
using namespace std;

int arr[101][101];
vector<vector<int> > vec(101);

int main() {
    int t;
    scanf_s("%d", &t);

    for (int i = 1; i <= t; i++) {
        int n, m;
        scanf_s("%d %d", &n, &m);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                arr[i][j] = 0;
            }
            vec[i].clear();
        }

        for (int i = 1; i <= m; i++) {
            int a, b;
            scanf_s("%d %d", &a, &b);
            arr[a][b] = 1;
            vec[a].push_back(b);
        }

        printf("#%d\n", i);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }

        for (int i = 1; i <= n; i++) {
            if (!vec[i].empty()) {
                for (auto itr = vec[i].begin(); itr != vec[i].end(); itr++) {
                    printf("%d ", *itr);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
