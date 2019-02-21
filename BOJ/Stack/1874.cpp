#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<char> print;

void pushStack(stack<int>& st, int num) {
    st.push(num);
    print.push_back('+');
}

void popStack(stack<int>& st) {
    st.pop();
    print.push_back('-');
}

int main() {
    int n, element, flag;
    stack<int> st;
    vector<int> in;

    cin >> n;
    in.reserve(n);

    for (int i = 0; i < n; i++) {
        cin >> element;
        in.push_back(element);
    }

    for (flag = 1; flag != in.front() + 1; flag++) {
        pushStack(st, flag);
    }
    popStack(st);
    in.erase(in.begin());

    while (!in.empty()) {
        if (st.empty() || (st.top() < in.front())) {
            pushStack(st, flag);
            flag++;
        }
        else if (st.top() == in.front()) {
            popStack(st);
            in.erase(in.begin());
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }

    for (auto itr = print.begin(); itr != print.end(); itr++) {
        cout << *itr << "\n";
    }

    return 0;
}
