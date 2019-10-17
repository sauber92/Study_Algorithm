#include <iostream>
using namespace std;

int d[12];

int solution(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (n == 3) {
        return 4;
    }

    if (d[n] > 0) {
        return d[n];
    }
    d[n] = solution(n - 1) + solution(n - 2) + solution(n - 3);
    return d[n];
}

int main() {
    int test_case;
    scanf("%d", &test_case);

    for (int t = 1; t <= test_case; t++) {
        int n;
        scanf("%d", &n);

        printf("%d\n", solution(n));
    }

    return 0;
}
