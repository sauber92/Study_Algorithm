#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkVPS(string s) {
    stack<char> st;

    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        }
        else {
            if (!st.empty()) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    int n;
    string ps;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ps;

        if (checkVPS(ps)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }


    return 0;
}
