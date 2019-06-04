#include <iostream>
using namespace std;

int main() {
    int n, s, ans = 0;

    cin >> n >> s;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < (1<<n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1<<j)) {
                sum += a[j];
            }
        }

        if (sum == s) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
