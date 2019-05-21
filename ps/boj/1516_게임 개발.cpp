#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define V_SIZE 10000

// 1516�� ���� ����
// �з�: ���� ����
// ����:
//		�ǹ��� ���� �ð��� �ǹ��� ���� ���� ���� �������� �ϴ� �ǹ��� �־����� ��
//		������ �ǹ��� ���� �ּ� �ð��� ���ϴ� ����
// Ǯ��:
//		���������� �� �ڿ�
//		���� ������� �ǹ� ���� �ð��� ���ϰ� �ű⿡ �����
//		���� �ǹ����� ���� �ش�. �̶� ������ ������ ū �ɷ� ���󰣴�.
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
		cin >> a; // i �ǹ� ���µ� �ɸ��� �ð�
		time[i] = a;
		while (1) {
			cin >> a;
			if (a == -1)
				break;
			adj[a].push_back(i);
			indegree[i]++;
		}
	}

	// ���� ����
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			pq.push(-i);
	}
	while (!pq.empty()) {
		int now = -pq.top();
		pq.pop();

		ans[now] += time[now];

		// now���� �����ϴ� ������ indegree ���߱�
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