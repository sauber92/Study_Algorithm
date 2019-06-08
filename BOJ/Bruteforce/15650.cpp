#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> answer, check;
    for (int i = 0; i < n; i++) {
        answer.push_back(i+1);        
        if (i < m) {
            check.push_back(1);
        }
        else {
            check.push_back(0);
        }
    }

   do {
        for (int i = 0; i < n; i++) {
            if (check[i]) {
                cout << answer[i] << ' ';
            }
        }
        cout << '\n';
    } while (prev_permutation(check.begin(), check.end()));

    return 0;
}
