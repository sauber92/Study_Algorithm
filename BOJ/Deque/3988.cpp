#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

const int MAX = 10000000;

int calcSlidingWindow(int N, int K, int V[]) {
    int max_num, min_num, result = MAX;
    int pivot = N - K;
    deque<int> idx;

    for (int i = 0, j = 1; pivot + i < N; i++) {
        for (; j < pivot + i; j++) {
            while (!idx.empty() && V[j] - V[j-1] <= V[idx.back()] - V[idx.back()-1]) {
                idx.pop_back();
            }
            idx.push_back(j);
        }

        max_num = V[pivot+i-1] - V[i];
        min_num = V[idx.front()] - V[idx.front() - 1]; 
        result = min(result, max_num + min_num);
    }

    return result;
}

int main() {
    int N, K;
    int V[1000000];

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    sort(V, V + N);

    cout << calcSlidingWindow(N, K, V) << "\n";

    return 0;
}
