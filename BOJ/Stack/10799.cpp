#include <iostream>
#include <string>
#include <stack>
using namespace std;

int checkPipeNum(string s) {
    int nPipe = 0;
    stack<char> st;

    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        }
        else {
            if (!st.empty()) {
                st.pop();

                if (s[i-1] == '(') {
                    nPipe += st.size();
                }
                else {
                    nPipe += 1;
                }
            }
            else {
                return 0;
            }
        }
    }

    return nPipe;
}

int main() {
    string s;

    cin >> s;

    cout << checkPipeNum(s) << endl;
    
    return 0;
}
