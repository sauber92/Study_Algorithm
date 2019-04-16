#include <iostream>
using namespace std;

int GCD(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    else {
        return GCD(num2, num1%num2);
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int num1, num2, g;
        cin >> num1 >> num2;
        g = GCD(num1, num2);
        cout << (num1*num2)/g << "\n";
    }

    return 0;
}
