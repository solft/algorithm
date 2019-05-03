#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// ���� ��, ���� ��
#define VERTEX 100
#define EDGE 100

// �湮, �̹湮 ǥ��
#define VISITED true
#define UNVISITED false

// ����*���� ũ���� ���� ���
int adjMatrix[VERTEX][VERTEX];

// ���� �� ��ŭ�� ���� ����Ʈ
vector<int> adjList[VERTEX];

// �湮 ǥ��: �湮 - true, �̹湮 - false
bool isVisited[VERTEX];

// ���� �湮 ���� ǥ��
int edgeTo[VERTEX];

// DFS: �� ������ �� ���� ���� ���� �������� �̵�
void dfs(int v) {
	isVisited[v] = VISITED; // v �湮
	for (int w = 0; w < (int)adjList[v].size(); w++)
		if (!isVisited[w])
			dfs(w);
}

// BFS: �� �������� �� �� �ִ� ���� queue�� �ְ� ����
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

// CC: ����� ������Ʈ ���ϱ�
int cc[VERTEX]; // cc[i] = a; i�� vertex�� ������Ʈ id
int componentId = 0;
void connectComponent() {
	// ��� �������� dfs(or bfs)�� �ѹ��� �õ��Ѵ�.(�湮������ ����)
	for (int v = 0; v < VERTEX; v++) {
		if (!isVisited[v]) {
			ccDFS(v);
			componentId++;
		}
	}
}

void ccDFS(int v) {
	isVisited[v] = VISITED; // v �湮
	cc[v] = componentId;
	for (int w = 0; w < (int)adjList[v].size(); w++)
		if (!isVisited[w])
			ccDFS(w);
}

// FloodFill: ����� ������Ʈ�� ��ȣ�� ���̰ų� ��ĥ
int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 }; // 2���� �迭 �̵��ϴ� ��ũ��
int dc[] = {  0,  1, 1, 1, 0,-1,-1, -1 }; // 12�ú��� �ð���� ����

// c1 ������ ���� c2�� �ٲٴ� floodfill
int floodfill(int r, int c, char c1, char c2) {
	// ��� �ٱ��� ������� �˻�
	if (r < 0 || r >= VERTEX || c < 0 || c >= VERTEX) return 0;
	if (adjMatrix[r][c] != c1) return 0;
	int ans = 1;
	adjMatrix[r][c] = c2;
	for (int d = 0; d < 8; d++)
		ans += floodfill(r + dr[d], c + dc[d], c1, c2);
	return ans;
}