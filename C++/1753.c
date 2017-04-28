#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

// 그래프 구조체
// Vertex와 Edge 생성
struct Graph {
	int V;
	int E;
	int** Adj;
};

// 방향그래프의 Edge 구조체
// 방향(to)와 weight
struct Edge {
	int to;
	int weight;
};

// Edge의 weight 비교연산자
// STL priority_queue에서 사용
struct Compare {
	bool operator()(struct Edge E1, struct Edge E2) {
		return E1.weight > E2.weight;
	}
};

// main에서 MakeGraph 호출
// MakeGraph에서 Dijkstra 호출
// Dijkstra에서 BackTracking 호출
void MakeGraph();			// 입력 -> 그래프 생성
void Dijkstra();			// 다익스트라 알고리즘계산
void BackTracking();	// 최단경로: 스택에 넣고 백트래킹 & 출력

int main() {
	MakeGraph();

	return 0;
}

void MakeGraph() {
	// 그래프 생성: V, E
	struct Graph G;
	// 그래프 생성 : 시작정점(K = start), 종료정점
	int start, end;

	// 그래프 정점, 간선 입력
	scanf("%d %d", &(G->V), &(G->E));

	// 그래프 초기화 
	for(int i = 0; i < G->V, i++) {

	}

	// 간선 입력
	for(int i = 0; i < G->V; u++) {

	}
}

void Dijkstra() {
	// STL priority_queue
	// priority_queue<자료형, 구현체, 비교연산자>
	priority_queue<Edge, vector<Edge> Compare> pq;

	// 초기화 : start 정점부터

	// 현재 V와 연결된 정점 검사

	// 연결된 노드 거리 계산 & 업데이트
	// 조건 : 방문했는지 안했는지

	// 예외처리
	// 올바르면 BackTracking() 호출

	// 올바르지 않으면 종료
}

void BackTracking() {
	// 역추적 스택 생성

	// 스택 push

	// 스택 pop & 출력

	// 예외처리
	// 연결이 없으면 INF 출력
}
