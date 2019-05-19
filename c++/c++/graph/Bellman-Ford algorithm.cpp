#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define INF 2000000000

// 벨만-포드 알고리즘(Bellman-Ford algorithm)
int main() {
	int n, m, x; // 정점, 간선, 시작점
	vector<tuple<int, int, int>> edges; // 간선 리스트
	int distance[100]; // 시작점에서 거리 저장할 배열

	// 그래프 만들기
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges.push_back({ a, b, w });
	}

	// x 노드에서 벨만-포드 알고리즘 시작
	cin >> x;
	
	for (int i = 1; i <= n; i++)
		distance[i] = INF;
	distance[x] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			distance[b] = min(distance[b], distance[a] + w);
		}
	}

	// 결과 출력
	for (int i = 1; i <= n; i++)
		cout << distance[i] << ' ';
	cout << '\n';
}