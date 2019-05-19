#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define INF 2000000000

// ���ͽ�Ʈ�� �˰���(Dijkstra's algorithm>
int main() {

	int n, m; // ����, ����
	int x; // ������
	vector<pair<int, int>> adj[100]; // adj[a] = [{b, w}, ... ] a ��忡 ����� ����ġ w¥�� b ���� ���� ����
	priority_queue<pair<int, int>> q;
	int distance[100];
	bool processed[100] = { false, };

	// �׷��� �����(���� �׷���)
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({ b, w });
		adj[b].push_back({ a, w });
	}

	// x ��忡�� ���ͽ�Ʈ�� �˰��� ����
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
				q.push({ -distance[b], b }); // b������ �Ÿ��� ������ ���� => priority_queue�� ū ���� �����ϹǷ�
			}
		}
	}

	// ��� ���
	for (int i = 1; i <= n; i++)
		cout << distance[i] << ' ';
	cout << '\n';
}