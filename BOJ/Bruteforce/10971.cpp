#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000 * 4;

int main() {
    int n, ans = MAX;
    scanf("%d", &n);

    vector<int> d(n);
    int w[n][n];

    for (int i = 0; i < n; i++) {
        d[i] = i;
        for (int j = 0; j < n; j++) {
            scanf("%d", &w[i][j]);
        }
    }

    do {
        bool ok = true;
        int sum = 0;

        for (int i = 0; i < n-1; i++) {
            if (w[d[i]][d[i+1]] == 0) {
                ok = false;
            }
            else {
                sum += w[d[i]][d[i+1]];
            }

            if (ok && w[d[n-1]][d[0]] != 0) {
                sum += w[d[n-1]][d[0]];
                ans = min(ans, sum);
            }
        }

    } while (next_permutation(d.begin()+1, d.end()));

    printf("%d\n", ans);
    
    return 0;
}
