#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a;
    a.reserve(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> op;
    op.reserve(n-1);
    for (int i = 0; i < 4; i++) {
        int operation;
        cin >> operation;
        for (int j = 0; j < operation; j++) {
            op.push_back(i);
        }
    }
    sort(op.begin(), op.end());

    int M = -1000000000, m = 1000000000;
    do {
        int result = a[0];
        for (int i = 0; i < n-1; i++) {
            if (op[i] == 0) {
                result += a[i+1];
            } else if (op[i] == 1) {
                result -= a[i+1];
            } else if (op[i] == 2) {
                result *= a[i+1];
            } else {
                result /= a[i+1];
            }
        }
        M = max(M, result);
        m = min(m, result);
    } while (next_permutation(op.begin(), op.end()));

    cout << M << '\n' << m << '\n';

    return 0;
}
