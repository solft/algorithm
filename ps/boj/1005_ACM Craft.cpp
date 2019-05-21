#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 1005번 ACM Craft
// 분류: 위상 정렬
// 문제:
//		건설 순서와 건설 비용이 주어질때 해당 건물을 짓기위한 최소 시간 구하기
// 풀이:
//		위상 정렬을 한 뒤에 
//		해당 건물을 짓기 위해 필요한 건물들의 건설 시간을 더하면 된다.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k; // 건물수, 건설 순서 규칙
		vector<int> time; // 건물 건설 시간
		vector<vector<int>> adj; // 그래프
		vector<int> indegree;
		vector<int> ans;
		priority_queue<int> pq;

		cin >> n >> k;
		time.resize(n + 1, 0);
		adj.resize(n + 1);
		indegree.resize(n + 1, 0);
		ans.resize(n + 1, 0);
		for (int i = 1; i <= n; i++)
			cin >> time[i];
		for (int i = 1; i <= k; i++) {
			int departure, destination;
			cin >> departure >> destination;
			adj[departure].push_back(destination);
			indegree[destination]++;
		}

		// 위상정렬
		for (int i = 1; i <= n; i++)
			if (indegree[i] == 0)
				pq.push(-i);

		while (!pq.empty()) {
			int now = -pq.top();
			pq.pop();

			ans[now] += time[now];

			for (auto next : adj[now]) {
				ans[next] = max(ans[next], ans[now]);
				indegree[next]--;
				if (indegree[next] == 0)
					pq.push(-next);
			}
		}

		
		int target;
		cin >> target;
		cout << ans[target] << '\n';
	}
}