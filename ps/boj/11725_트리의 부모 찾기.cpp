#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 11725�� Ʈ���� �θ� ã��
// �з�: Ʈ��
// ����:
//		Ʈ���� ��Ʈ�� ���ϴ� ����
// Ǯ��:
//		�׷���ó�� �����ؼ�
//		�׷����� ����� 1�� ������
//		BFS�� �����ؼ� ���� ��� ���� �θ� �������ش�.
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

	// BFS ����
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