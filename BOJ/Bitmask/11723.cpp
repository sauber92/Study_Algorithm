#include <iostream>
#include <string>
using namespace std;

void operateSet(int &s, string op) {
    int num;

    if (op.compare("add") == 0) {
        scanf("%d", &num);
        num = (1 << num);
        s |= num;
    }
    else if (op.compare("remove") == 0) {
        scanf("%d", &num);
        num = (1 << num);
        s &= (~num);
    }
    else if (op.compare("check") == 0) {
        scanf("%d", &num);
        num = (1 << num);
        if ((s & num) != 0) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
    else if (op.compare("toggle") == 0) {
        scanf("%d", &num);
        num = (1 << num);
        s ^= num;
    }
    else if (op.compare("all") == 0) {
        s = ((1 << 21) - 2);
    }
    else {
        s = 0;
    }
    return;
}

int main() {
    int m, s = 0;
    string op;

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char op[10];
        scanf("%s", op);
        operateSet(s, op); 
    }

    return 0;
}
