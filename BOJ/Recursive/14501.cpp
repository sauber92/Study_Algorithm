#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = 0;
vector<int> t, p;

void go(int day, int sum) {
    if (day == n) {
        ans = max(ans, sum);
        return;
    }

    if (day > n) {
        return;
    }

    go(day+t[day], sum+p[day]);
    go(day+1, sum);
}

int main() {
    cin >> n;
    
    t.resize(n);
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }

    go(0, 0);

    cout << ans << '\n';
    
    return 0;
}
