#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool check(string& str) {
    int mo = 0, ja = 0;
    for (char x : str) {
        if (x == 'a' || x == 'e' || x == 'i' ||
            x == 'o' || x == 'u') {
            mo++;
        }
        else {
            ja++;
        }
    }

    if (mo >= 1 && ja >= 2) {
        return true;
    }
    else {
        return false;
    }
}

void go(int n, vector<char>& alpha, string password, int idx) {
    if ((unsigned)n == password.length()) {
        if (check(password)) {
            cout << password << '\n';
        }
        return;
    }

    if ((unsigned)idx >= alpha.size()) {
        return;
    }

    go(n, alpha, password + alpha[idx], idx+1);
    go(n, alpha, password, idx+1);
}
    
int main() {
    int l, c;
    cin >> l >> c;

    vector<char> alpha(c);
    for (int i = 0; i < c; i++) {
        cin >> alpha[i];
    }
    sort(alpha.begin(), alpha.end());

    go(l, alpha, "", 0);

    return 0;
}
