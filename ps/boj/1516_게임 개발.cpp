#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define V_SIZE 10000

// 1516번 게임 개발
// 분류: 위상 정렬
// 문제:
//		건물을 짓는 시간과 건물을 짓기 위해 먼저 지어져야 하는 건물이 주어졌을 때
//		각각의 건물을 짓는 최소 시간을 구하는 문제
// 풀이:
//		위상정렬을 한 뒤에
//		위상 순서대로 건물 짓는 시간을 더하고 거기에 연결된
//		다음 건물에도 더해 준다. 이때 기존의 값보다 큰 걸로 따라간다.
vector<vector<int>> adj;
vector<int> time;
vector<int> indegree;
priority_queue<int> pq;

vector<int> ans;
int n;

int main() {
	cin >> n;
	adj.resize(n + 1);
	time.resize(n + 1);
	indegree.resize(n + 1, 0);
	ans.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a; // i 건물 짓는데 걸리는 시간
		time[i] = a;
		while (1) {
			cin >> a;
			if (a == -1)
				break;
			adj[a].push_back(i);
			indegree[i]++;
		}
	}

	// 위상 정렬
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			pq.push(-i);
	}
	while (!pq.empty()) {
		int now = -pq.top();
		pq.pop();

		ans[now] += time[now];

		// now에서 도달하는 정점의 indegree 낮추기
		for (auto future : adj[now]) {
			ans[future] = max(ans[future], ans[now]);
			indegree[future]--;
			if (indegree[future] == 0)
				pq.push(-future);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
}