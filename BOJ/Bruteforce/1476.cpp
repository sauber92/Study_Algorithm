#include <iostream>
using namespace std;

const int MAX = 15 * 28 * 19;

int main() {
    int E, S, M;
    int year_E, year_S, year_M;

    scanf("%d %d %d", &E, &S, &M);

    for (int i = 0; i <= MAX/15; i++) {
        for (int j = 0; j <= MAX/28; j++) {
            for (int k = 0; k <= MAX/19; k++) {
                year_E = i*15 + E;
                year_S = j*28 + S;
                year_M = k*19 + M;

                if ((year_E == year_S) && (year_S == year_M)) {
                    printf("%d\n", year_E);
                    return 0;
                }
            }
        }
    }

    return 0;
}
