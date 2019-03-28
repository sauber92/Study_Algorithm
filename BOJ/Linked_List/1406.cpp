#include <iostream>
#include <cstring>
#include <list>
using namespace std;

void processEditor(list<char>& cursor, list<char>::iterator& c, char order) {
    if (order == 'L') {
        if (c != cursor.begin()) {
            c--; 
        }
    }
    else if (order == 'D') {
        if (c != cursor.end()) {
            c++;
        }
    }
    else if (order == 'B') {
        if (c != cursor.begin()) {
            auto tmp = c;
            tmp--;
            cursor.erase(tmp);
        }
    }
    else if (order == 'P') {
        char input;
        cin >> input;
        cursor.insert(c, input);
    }
}

int main() {
    string str;
    int N;
    char order;

    cin >> str >> N;

    list<char> cursor(str.begin(), str.end());
    auto c = cursor.end();

    for (int i = 0; i < N; i++) {
        cin >> order;
        processEditor(cursor, c, order);
   }

    for (auto itr = cursor.begin(); itr != cursor.end(); itr++) {
        cout << *itr;
    }
    cout << "\n";

    return 0;
}
