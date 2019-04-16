#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int GCD(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    else {
        return GCD(num2, num1 % num2);
    }
}

void storeGCD(queue<int>& q, vector<int>& r) {
    unsigned int size = q.size();
    for (unsigned int i = 0; i < size; i++) {
        int front = q.front();

        queue<int> tmp = q;
        tmp.pop();

        while (!tmp.empty()) {
            r.push_back( GCD(front, tmp.front()) );
            tmp.pop();
        }
        q.pop();
    }
}

int main() {
    int t, n, num;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long sum = 0;
        queue<int> input;
        vector<int> result;

        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> num;
            input.push(num);
        }

        storeGCD(input, result);

        for (auto itr = result.begin(); itr != result.end(); itr++) {
            sum += *itr; 
        }
        cout << sum << "\n";
    }

    return 0;
}
