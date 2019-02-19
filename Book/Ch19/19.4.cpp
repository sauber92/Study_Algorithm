#include <iostream>
#include <string>
#include <stack>
using namespace std;

const string opening = "({[";
const string closing = ")}]";

bool checkString(string s) {
    stack<char> st;

    for (unsigned int i = 0; i < s.length(); i++) {
        if (opening.find(s[i]) != string::npos) {
            st.push(s[i]);
        }
        else {
            if (!st.empty()) {
                if (opening.find(st.top()) == closing.find(s[i])) {
                    st.pop();
                }
                else {
                    return false;
                }
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
    string s;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;

        if (checkString(s)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
