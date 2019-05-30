// 2부터 입력변수 N까지의 소수의 합 구하기
// ex) (N = 7) => 17 ... {2,3,5,7}

#include <vector>
using namespace std;

const int MAX = 10000000;
bool check[MAX+1];

void Eratos(int num) {
    check[0] = check[1] = true;
    for (int i = 2; i <= num; i++) {
        if (check[i] == false) {
            for (int j = i*2; j <= num; j+=i) {
                check[j] = true;
            }
        }
    }
}

long long solution(int N) {
    long long answer = 0;

    Eratos(N);
    for (int i = 2; i <= N; i++) {
        if (check[i] == false) {
            answer += i;
        }
    }

    return answer;
}
