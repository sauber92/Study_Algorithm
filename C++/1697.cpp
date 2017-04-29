#include <iostream>
#include <queue>
using namespace std;

int main() {
	// 큐 생성
	queue<int> q;

	// 트리
	int tree[100000] = {0, };

	// now 변수는 수빈이의 위치.
	int N, K, now;
	cin >> N >> K;

	// 예외처리
	if(N < 0 || N > 100001 ) {
		return -1;
	}
	if(K < 0 || K > 100001 ) {
		return -1;
	}

	// 트리 구조를 그리면서 확인하면 BFS로 해결할 수 있는 것을 알 수 있다.
	// 수빈이의 위치를 큐에 넣음 & 트리는 1
	q.push(N);
	tree[N] = 1;

	// BFS 시작
	while(!q.empty()) {
		now = q.front();
		q.pop();

		// now == K이면 출력
		if(now == K) {
			cout << tree[now] -1;
		}

		// 수빈이의 위치 -1한 곳이 0 이상이고,
		// 이 위치에 아직 방문을 안했을 때
		if(now - 1 >= 0 && tree[now - 1] == 0) {
			tree[now - 1] = tree[now] + 1;
			q.push(now - 1);
		}

		// 수빈이의 위치 +1한 곳이 100000 이상이고,
		// 이 위치에 아직 방문을 안했을 때
		if(now + 1 <= 100000 && tree[now + 1] == 0) {
			tree[now + 1] = tree[now] + 1;
			q.push(now + 1);
		}

		// 수빈이의 위치 *2한 곳이 100000 이상이고,
		// 이 위치에 아직 방문을 안했을 때
		if(now * 2 <= 100000 && tree[now * 2] == 0) {
			tree[now * 2] = tree[now] + 1;
			q.push(now * 2);
		}
	}
	
	return 0;
}
