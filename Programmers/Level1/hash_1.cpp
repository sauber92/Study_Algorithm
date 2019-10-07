#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multimap<string, int> m;

    for (unsigned int i = 0; i < participant.size(); i++) {
        m.insert(make_pair(participant[i], i));
    }

    for (unsigned int i = 0; i < completion.size(); i++) {
        m.erase(m.find(completion[i]));
    }

    for (auto itr = m.begin(); itr != m.end(); itr++) {
        answer = itr->first;
        return answer;
    }
}

int main() {
    vector<string> p, c;
    int p_len, c_len;
    string p_name, c_name;

    cin >> p_len;
    for (int i = 0; i < p_len; i++) {
        cin >> p_name;
        p.push_back(p_name);
    }

    cin >> c_len;
    for (int i = 0; i < c_len; i++) {
        cin >> c_name;
        c.push_back(c_name);
    }

    cout << "=====" << endl;
    cout << solution(p, c) << endl;

    return 0;
}
