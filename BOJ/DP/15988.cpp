#include <iostream>
using namespace std;

long long d[1000001];

int main() {
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    int test_case;
    scanf("%d", &test_case);

    for (int t = 1; t <= test_case; t++) {
        int n;
        scanf("%d", &n);

        for (int i = 4; i <= 1000000; i++) {
            d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % 1000000009;
        }

        printf("%d\n", d[n]);
    }

    return 0;
}
