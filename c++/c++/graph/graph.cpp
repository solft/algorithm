#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 정점 수, 간선 수
#define VERTEX 100
#define EDGE 100

// 방문, 미방문 표시
#define VISITED true
#define UNVISITED false

// 정점*정점 크기의 인접 행렬
int adjMatrix[VERTEX][VERTEX];

// 간선 수 만큼의 인접 리스트
vector<int> adjList[VERTEX];

// 방문 표시: 방문 - true, 미방문 - false
bool isVisited[VERTEX];

// 이전 방문 정점 표시
int edgeTo[VERTEX];

// DFS: 한 정점에 들어가 다음 접근 가능 정점으로 이동
void dfs(int v) {
	isVisited[v] = VISITED; // v 방문
	for (int w = 0; w < (int)adjList[v].size(); w++)
		if (!isVisited[w])
			dfs(w);
}

// BFS: 한 정점에서 갈 수 있는 정점 queue에 넣고 다음
void bfs(int v) {
	isVisited[v] = VISITED;
	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int w = 0; w < (int)adjList[now].size(); w++)
			if (!isVisited[w]) {
				edgeTo[w] = now;
				isVisited[w] = VISITED;
				q.push(w);
			}
	}
}

// CC: 연결된 컴포넌트 구하기
int cc[VERTEX]; // cc[i] = a; i번 vertex의 컴포넌트 id
int componentId = 0;
void connectComponent() {
	// 모든 정점에서 dfs(or bfs)를 한번씩 시도한다.(방문했으면 안함)
	for (int v = 0; v < VERTEX; v++) {
		if (!isVisited[v]) {
			ccDFS(v);
			componentId++;
		}
	}
}

void ccDFS(int v) {
	isVisited[v] = VISITED; // v 방문
	cc[v] = componentId;
	for (int w = 0; w < (int)adjList[v].size(); w++)
		if (!isVisited[w])
			ccDFS(w);
}

// FloodFill: 연결된 컴포넌트에 번호를 붙이거나 색칠
int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 }; // 2차원 배열 이동하는 테크닉
int dc[] = {  0,  1, 1, 1, 0,-1,-1, -1 }; // 12시부터 시계방향 순서

// c1 문자인 곳을 c2로 바꾸는 floodfill
int floodfill(int r, int c, char c1, char c2) {
	// 행렬 바깥을 벗어나는지 검사
	if (r < 0 || r >= VERTEX || c < 0 || c >= VERTEX) return 0;
	if (adjMatrix[r][c] != c1) return 0;
	int ans = 1;
	adjMatrix[r][c] = c2;
	for (int d = 0; d < 8; d++)
		ans += floodfill(r + dr[d], c + dc[d], c1, c2);
	return ans;
}