#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 1005�� ACM Craft
// �з�: ���� ����
// ����:
//		�Ǽ� ������ �Ǽ� ����� �־����� �ش� �ǹ��� �������� �ּ� �ð� ���ϱ�
// Ǯ��:
//		���� ������ �� �ڿ� 
//		�ش� �ǹ��� ���� ���� �ʿ��� �ǹ����� �Ǽ� �ð��� ���ϸ� �ȴ�.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k; // �ǹ���, �Ǽ� ���� ��Ģ
		vector<int> time; // �ǹ� �Ǽ� �ð�
		vector<vector<int>> adj; // �׷���
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

		// ��������
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