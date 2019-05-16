#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calc(vector<int> vec) {
    int sum = 0;

    for (unsigned int i = 0; i < vec.size()-1; i++) {
        sum += abs(vec[i] - vec[i+1]);
    }

    return sum;
}

int main() {
    int N, tmp, ans = 0;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    do {
        tmp = calc(A);
        ans = max(ans, tmp);
    } while (next_permutation(A.begin(), A.end()));

    cout << ans << '\n';

    return 0;
}
