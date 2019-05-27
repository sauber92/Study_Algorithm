#include <iostream>
#include <vector>
using namespace std;

int n, s;
vector<int> nums;
int cnt = 0;

void go(int sum, int idx) {
    if (idx == n) {
        if (sum == s) {
            cnt++;
        }
        return;
    }

    go(sum + nums[idx], idx+1);
    go(sum, idx+1);
}

int main() {
    cin >> n >> s;

    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    go(0, 0);

    if (s == 0) {
        cnt--;
    }

    cout << cnt << '\n';

    return 0;
}
