#include <iostream>
#include <queue>
using namespace std;

int printAnswer(int order, priority_queue<int> pq, queue<pair<int, int> > q) {
	int answer = 0;
	int idx, val;

	while (!q.empty()) {
		idx = q.front().first;
		val = q.front().second;

		if (pq.top() == val) {
			if (order == idx) {
				answer++;
				break;
			}
			else {
				q.pop();
				pq.pop();
				answer++;
			}
		}
		else {
			q.pop();
			q.push({idx, val});
		}
	}

	return answer;
}

int main() {
    int nCase, nDoc, order, pq;

	cin >> nCase;
	
	for (int i = 0; i < nCase; i++) {
		priority_queue<int> priority;
		queue<pair<int,int> > queue;

		cin >> nDoc;
		cin >> order;

		for (int j = 0; j < nDoc; j++) {
			cin >> pq;
			priority.push(pq);
			queue.push({j, pq});
		}

		cout << printAnswer(order, priority, queue) << "\n";
	}

	return 0;
}
