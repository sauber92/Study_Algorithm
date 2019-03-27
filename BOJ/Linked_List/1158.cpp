#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, M;
    queue<int> q;

    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        q.push(i+1);
    }

    cout << "<";
    while (q.size() != 1) {
        for (int i = 1; i < M; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">\n";

    return 0;
}
