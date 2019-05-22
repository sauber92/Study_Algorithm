#include <iostream>
using namespace std;

int ans;

void calc(int n, int sum) {
    if (sum == n) {
        ans++;
    }

    if (sum > n) {
        return;
    }

    calc(n, sum+1);
    calc(n, sum+2);
    calc(n, sum+3);
}

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        ans = 0;
        cin >> n;
        calc(n, 0);
        cout << ans << '\n';
    }

    return 0;
}
