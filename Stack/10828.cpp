#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int n, x;
    string s;
    stack<int> st;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;

        if (s == "push") {
            cin >> x;
            st.push(x);
        }
        else if (s == "pop") {
            if (!st.empty()) {
                cout << st.top() << endl;
                st.pop();
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if (s == "size") {
            cout << st.size() << endl;
        }
        else if (s == "empty") {
            if (!st.empty()) {
                cout << "0" << endl;
            }
            else {
                cout << "1" << endl;
            }
        }
        else if (s == "top") {
            if (!st.empty()) {
                cout << st.top() << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
    }

    return 0;
}
