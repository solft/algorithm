#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 11725번 트리의 부모 찾기
// 분류: 트리
// 문제:
//		트리의 루트를 구하는 문제
// 풀이:
//		그래프처럼 생각해서
//		그래프를 만들고 1번 노드부터
//		BFS로 시작해서 다음 노드 갈때 부모를 저장해준다.
int n;
vector<vector<int>> adjList;
int visit[100010];
int parent[100010];

int main() {
	cin >> n;
	adjList.resize(n + 1);

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	// BFS 시작
	queue<int> bq;
	bq.push(1);

	while (!bq.empty()) {
		int now = bq.front();
		bq.pop();

		for (int next : adjList[now]) {
			if (parent[next] == 0) {
				bq.push(next);
				parent[next] = now;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
}