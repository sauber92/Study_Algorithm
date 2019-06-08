#include <iostream>
using namespace std;

int answer[10];

void go(int idx, int n, int m) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
    }

    if (idx > m) {
        return;
    }

    for (int i = 1; i <= n; i++) {
        answer[idx] = i;
        go(idx+1, n, m);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    go(0, n, m);

    return 0;
}
