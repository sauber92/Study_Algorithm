#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int M = -1000000000;
int m =  1000000000;

void go(vector<int>& a, int idx, int ans,
        int plus, int minus, int mul, int div) {
    if (idx >= n) {
        M = max(ans, M);
        m = min(ans, m);
        return;
    }

    if (plus > 0) {
        go(a, idx+1, ans+a[idx], plus-1, minus, mul, div);
    }
    if (minus > 0) {
        go(a, idx+1, ans-a[idx], plus, minus-1, mul, div);
    }
    if (mul > 0) {
        go(a, idx+1, ans*a[idx], plus, minus, mul-1, div);
    }
    if (div > 0) {
        go(a, idx+1, ans/a[idx], plus, minus, mul, div-1);
    }
}

int main() {
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int plus, minus, mul, div;
    cin >> plus >> minus >> mul >> div;

    go(a, 1, a[0], plus, minus, mul, div);

    cout << M << '\n' << m << '\n';

    return 0;
}
