#include <iostream>
using namespace std;

// 그래프를 전역변수로 설정
// 정점의 크기가 1 <= N <= 100 이므로 그래프의 최대크기는 100*100
int graph[100][100] = {0, };

int main() {
	int N;
	int i, k, j;

	cin >> N;

	// 예외처리
	if(N < 1 || N > 100) {
		return -1;
	}

	// 입력
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	// 플로이드 알고리즘
	// 각 정점에서 다른 모든 정점까지의 최단 거리를 구하는 알고리즘 - 동적계획법
	// 1. i->j 로 가는 방법
	// 2. i->k->j 로 가는 방법
	// 1, 2의 방법이 있으면 행렬에 "1" 넣기
	for(k = 0; k < N; k++) {
		for(i = 0; i < N; i++) {
			for(j = 0; j < N; j++) {
				if(graph[i][k] && graph[k][j]) {
					graph[i][j] = 1;
				}
			}
		}
	}

	// 출력
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
