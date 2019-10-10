#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf_s("%d", &t);

    for (int i = 1; i <= t; i++) {
        int n;
        scanf_s("%d", &n);

        vector<int> vec;
        for (int i = 1; i <= n; i++) {
            vec.push_back(i);
        }

        do {
            for (int i = 0; i < n; i++) {
                printf("%d ", vec[i]);
            }
            printf("\n");
        } while (next_permutation(vec.begin(), vec.end()));
    }

    return 0;
}
