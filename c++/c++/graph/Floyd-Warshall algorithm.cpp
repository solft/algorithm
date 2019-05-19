#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define INF 2000000000

// �÷��̵�-���� �˰���(Floyd-Warshall algorithm)
int n, m;
int adj[100][100];
int dist[100][100];

int main() {

	cin >> n >> m;

	// �׷��� �����
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a][b] = w;
		adj[b][a] = w;
	}

	// dist �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else if (adj[i][j]) dist[i][j] = adj[i][j];
			else dist[i][j] = INF;
		}
	}

	// �÷��̵�-���� �˰���
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	// ��� ���
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}