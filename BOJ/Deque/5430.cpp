#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

void operateFunc(string funcP, char* arrX) {
    deque<int> dq;
    char* tmp = strtok(arrX, "[,]");

    while (tmp != NULL) {
        int num = stoi(tmp);
        dq.push_back(num);
        tmp = strtok(NULL, "[,]");
    }
    
    bool rev = false, del = false;
    for (auto itr = funcP.begin(); itr != funcP.end(); itr++) {
        if (*itr == 'R') {
            rev = !rev;
        }
        else {
            if (!dq.empty()) {
                if (rev) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
            else {
                del = true;
                break;
            }
        }
    }

    if (!del) {
        int size = dq.size();
        cout << "[";
        if (size != 0) {
            if (rev) {
                for (int i = 0; i != size; i++) {
                    if (dq.size() != 1) {
                        cout << dq.back() << ",";
                        dq.pop_back();
                    }
                    else {
                        cout << dq.back();
                    }
                }
            }
            else {
                for (int i = 0; i != size; i++) {
                    if (dq.size() != 1) {
                        cout << dq.front() << ",";
                        dq.pop_front();
                    }
                    else {
                        cout << dq.back();
                    }
                }
            }
        }
        cout << "]\n";
    }
    else {
        cout << "error\n";
    }
}

int main() {
    int nCase, nArr;
    string funcP;
    char arrX[400001]; // [100,100,100,...,100] 일 경우 최대 400001

    cin >> nCase;

    for (int i = 0; i < nCase; i++) {
        cin >> funcP;
        cin >> nArr;
        cin >> arrX;
        operateFunc(funcP, arrX);
    }

    return 0;
}
