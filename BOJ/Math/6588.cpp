#include <iostream>
using namespace std;

const int MAX = 1000000;
int prime[MAX];
bool check[MAX+1];
int pn = 0;

void Eratos(int num) {
    for (int i = 2; i <= num; i++) {
        if (check[i] == false) {
            prime[pn++] = i;
            for (int j = i*2; j <= num; j+=i) {
                check[j] = true;
            }
        }
    }
}

void calcGoldbach(int sum) {
    for (int i = 1; i < pn; i++) {
        if (check[sum - prime[i]] == false) {
            cout << sum << " = " << prime[i] << " + " << sum - prime[i] << "\n";
            break;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    Eratos(MAX);

    while (1) {
    int sum;
        cin >> sum;
        if (sum == 0) {
            break;
        }
        calcGoldbach(sum);
    }

    return 0;
}
