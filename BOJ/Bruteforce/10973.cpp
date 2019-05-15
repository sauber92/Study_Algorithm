#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, num;
    vector<int> in;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        in.push_back(num);
    }

    if (prev_permutation(in.begin(), in.end())) {
        for (int i = 0; i < N; i++) {
            cout << in[i] << " ";
        }
        cout << "\n";
    }
    else {
        cout << "-1\n";
    }


    return 0;
}
