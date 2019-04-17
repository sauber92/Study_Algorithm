#include <iostream>
#include <set>
using namespace std;

const int H = 100;
set<int> s;

void findExtra(int sum_extra) {
    for (auto i = s.begin(); i != s.end(); i++) {
        int num1 = *i;
        int num2 = sum_extra - num1;

        auto itr = s.find(num2);
        if (itr != s.end()) {
            s.erase(num1);
            s.erase(num2);
            break;
        }
    }
}

void printSet() {
    for (auto itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << "\n";
    }
}

int main() {
    int sum_all = 0;

    for (int i = 0; i < 9; i++) {
        int h;
        cin >> h;
        s.insert(h);
        sum_all += h;
    }

    int sum_extra = sum_all - H;

    findExtra(sum_extra);
    printSet();

    return 0;
}
