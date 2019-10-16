#include <iostream>
using namespace std;

int d[1000001];

int solution(int n) {
    if (n == 1) {
        return 0;
    }

    if (d[n] > 0) {
        return d[n];
    }

    d[n] = solution(n - 1) + 1;
    if (n % 3 == 0) {
        int tmp = solution(n / 3) + 1;
        if (d[n] > tmp) {
            d[n] = tmp;
        }
    }
    if (n % 2 == 0) {
        int tmp = solution(n / 2) + 1;
        if (d[n] > tmp) {
            d[n] = tmp;
        }
    }

    return d[n];
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", solution(n));

    return 0;
}
