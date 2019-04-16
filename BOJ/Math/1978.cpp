#include <iostream>
using namespace std;

bool isPrimeNum(int num) {
    if (num < 2) {
        return false;
    }

    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int N, count;
    cin >> N;

    count = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (isPrimeNum(num)) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
