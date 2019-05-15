#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    vector<int> init;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        init.push_back(i);
    }

    do {
        for (int i = 0; i < N; i++) {
            cout << init[i] << " ";
        }
        cout << "\n";
    } while(next_permutation(init.begin(), init.end()));

    return 0;
}
