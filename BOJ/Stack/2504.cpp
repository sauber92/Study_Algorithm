#include <iostream>
#include <string>
#include <stack>
using namespace std;

const string opening = "([";
const string closing = ")]";
const int value[2] = {2, 3};

int calcString(string s) {
    int sum = 0;
    int mul = 1;
    stack<char> st;

    for (unsigned int i = 0; i < s.length(); i++) {
        if (opening.find(s[i]) != string::npos) {
            mul *= value[opening.find(s[i])];
            st.push(s[i]);
        }
        else {
            if (!st.empty()) {
                if (opening.find(st.top()) == closing.find(s[i])) {
                    if (opening.find(s[i-1]) != string::npos) {
                        sum += mul;
                    }
                    mul /= value[closing.find(s[i])];
                    st.pop();
                }
                else {
                    sum = 0;
                    break;
                }
            }
            else {
                sum = 0;
                break;
            }
        }
    }

    if (!st.empty()) {
        sum = 0;
    }

    return sum;
}

int main() {
    string input;
    cin >> input;
    cout << calcString(input) << "\n";

    return 0;
}
