#include <iostream>
#include <string>
#include <deque>
using namespace std;

void funcDeque(string str, deque<int>& dq) {
    int X;

    if (str == "push_front") {
        cin >> X;
        dq.push_front(X);
    }
    else if (str == "push_back") {
        cin >> X;
        dq.push_back(X);
    }
    else if (str == "pop_front") {
        if (!dq.empty()) {
            cout << dq.front() << "\n";
            dq.pop_front();
        }
        else {
            cout << "-1\n";
        }
    }
    else if (str == "pop_back") {
        if (!dq.empty()) {
            cout << dq.back() << "\n";
            dq.pop_back();
        }
        else {
            cout << "-1\n";
        }
    }
    else if (str == "size") {
        cout << dq.size() << "\n";
    }
    else if (str == "empty") {
        cout << dq.empty() << "\n";
    }
    else if (str == "front") {
        int result;
        result = dq.empty() ? -1 : dq.front();
        cout << result << "\n";
    }
    else if (str == "back") {
        int result;
        result = dq.empty() ? -1 : dq.back();
        cout << result << "\n";
    }
}

int main() {
    int N;
    string str;
    deque<int> dq;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> str;
        funcDeque(str, dq);
    }

    return 0;
}
