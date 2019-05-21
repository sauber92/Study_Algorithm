#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while (1) {
        int k;
        cin >> k;

        if (k == 0) {
            break;
        }

        vector<int> s(k), next(k);
        for (int i = 0; i < k; i++) {
            if (i < k-6) {
                next[i] = 0;
            }
            else {
                next[i] = 1;
            }
            cin >> s[i];
        }

        vector<vector<int> > ans;
        do {
            vector<int> current;

            for (int i = 0; i < k; i++) {
                if (next[i] == 1) {
                    current.push_back(s[i]);
                }
            }

            ans.push_back(current);
        } while (next_permutation(next.begin(), next.end()));

        sort(ans.begin(), ans.end());

        for (unsigned int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < 6; j++) {
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}
