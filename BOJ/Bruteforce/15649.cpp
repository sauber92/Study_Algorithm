#include <iostream>
using namespace std;

bool check[10];
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
        if (check[i]) {
            continue;
        }
        check[i] = true;
        answer[idx] = i;
        go(idx+1, n, m);
        check[i] = false;
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    go(0, n, m);

    return 0;
}
