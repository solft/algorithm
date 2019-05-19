#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define INF 2000000000

// 다익스트라 알고리즘(Dijkstra's algorithm>
int main() {

	int n, m; // 정점, 간선
	int x; // 시작점
	vector<pair<int, int>> adj[100]; // adj[a] = [{b, w}, ... ] a 노드에 연결된 가중치 w짜리 b 노드로 가는 간선
	priority_queue<pair<int, int>> q;
	int distance[100];
	bool processed[100] = { false, };

	// 그래프 만들기(무향 그래프)
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({ b, w });
		adj[b].push_back({ a, w });
	}

	// x 노드에서 다익스트라 알고리즘 시작
	cin >> x;

	for (int i = 1; i <= n; i++)
		distance[i] = INF;
	distance[x] = 0;
	q.push({ 0, x });
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		if (processed[a]) continue;
		processed[a] = true;
		for (auto u : adj[a]) {
			int b = u.first, w = u.second;
			if (distance[a] + w < distance[b]) {
				distance[b] = distance[a] + w;
				q.push({ -distance[b], b }); // b까지의 거리를 음수로 저장 => priority_queue는 큰 값을 리턴하므로
			}
		}
	}

	// 결과 출력
	for (int i = 1; i <= n; i++)
		cout << distance[i] << ' ';
	cout << '\n';
}