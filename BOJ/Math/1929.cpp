#include <iostream>
using namespace std;

const int MAX = 1000000;
bool check[MAX+1];

void isPrimeNum(int num) {
    check[0] = true;
    check[1] = true;

    for (int i = 2; i <= num; i++) {
        if (check[i] == false) {
            for (int j = i+i; j <= num; j+=i) {
                check[j] = true;
            }
        }
    }
}

int main() {
    int M, N;
    cin >> M >> N;

    isPrimeNum(N);

    for (int i = M; i <= N; i++) {
        if (check[i] == false) {
            cout << i << "\n";
        }
    }

    return 0;
}
