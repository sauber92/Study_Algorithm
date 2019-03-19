#include <iostream>
#include <vector>
using namespace std;

const int ascend[8]  = {1,2,3,4,5,6,7,8};
const int descend[8] = {8,7,6,5,4,3,2,1};

void checkVector(vector<int>& v) {
    int asc = 0, des = 0;

    for (unsigned int i = 0; i != v.size(); i++) {
        if (v.at(i) == ascend[i]) {
            asc++;
        }
        else if (v.at(i) == descend[i]) {
            des++;
        }
    }

    if (asc == 8) {
        cout << "ascending\n";
    }
    else if (des == 8) {
        cout << "descending\n";
    }
    else {
        cout << "mixed\n";
    }
}

int main() {
    int num;
    vector<int> vec;

    for (int i = 0; i < 8; i++) {
        cin >> num;
        vec.push_back(num);
    }

    checkVector(vec);

    return 0;
}
