// 문자열의 가운데 있는 글자 출력
// ex1) abcd => bc
// ex2) abcde => c

#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    unsigned int size = s.length();

    if (size % 2 == 0) {
        int idx = (size/2) - 1;
        answer.push_back(s[idx]);
        answer.push_back(s[idx+1]);
    }
    else {
        int idx = size/2;
        answer.push_back(s[idx]);
    }

    return answer;
}
