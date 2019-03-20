#include <iostream>
#include <queue>
using namespace std;

class Chef {
    int num;
    int scores[5];

    public:
    Chef(int _num, int* _scores);
    ~Chef();
    int sum_scores();
};

Chef::Chef(int _num, int* _scores) {
    num = _num;
    for (int i = 0; i < 5; i++) {
        scores[i] = _scores[i];
    }
}

Chef::~Chef() {}

int Chef::sum_scores() {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += scores[i];
    }
    return sum;
}

int main() {
    Chef* chefs[5];
    priority_queue<pair<int, int> > pq;

    for (int i = 0; i < 5; i++) {
        int s[5] = {0,};
        for (int j = 0; j < 4; j++) {
            cin >> s[j];
        }
        chefs[i] = new Chef(i, s);
    }

    for (int i = 0; i < 5; i++) {
        pq.push({chefs[i]->sum_scores(), i+1});
    }
    cout << pq.top().second << " " << pq.top().first << "\n";

    for (int i = 0; i < 5; i++) {
        delete chefs[i];
    }

    return 0;
}
