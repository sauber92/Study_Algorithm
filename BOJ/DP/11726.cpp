#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n;
int d[1001];

int solution(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }

    if (d[n] > 0) {
        return d[n];
    }

    d[n] = (solution(n - 1) + solution(n - 2)) % 10007;

    return d[n];
}

int main() {
    scanf("%d", &n);

    printf("%d\n", solution(n));

    return 0;
}
