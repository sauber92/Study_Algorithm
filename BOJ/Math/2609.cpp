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

int LCM(int num1, int num2, int gcm) {
    return (num1 * num2) / gcm;
}

int main() {
    int num1, num2, g, l;
    cin >> num1 >> num2;

    g = GCD(num1, num2);
    l = LCM(num1, num2, g);

    cout << g << "\n";
    cout << l << "\n";

    return 0;
}
