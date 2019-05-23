#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

void go(vector<int>& s, int idx, int cnt) {
    if (cnt == 6) {
        for (int n : ans) {
            cout << n << ' ';
        }
        cout << '\n';
        return;
    }

    if ((unsigned)idx >= s.size()) {
        return;
    }

    ans.push_back(s[idx]);
    go(s, idx+1, cnt+1);

    ans.pop_back();
    go(s, idx+1, cnt);
}

int main() {
    while (1) {
        int k;
        cin >> k;

        if (k == 0) {
            break;
        }

        vector<int> s(k);
        for (int i = 0; i < k; i++) {
            cin >> s[i];
        }

        go(s, 0, 0);
        cout << '\n';
    }

    return 0;
}
