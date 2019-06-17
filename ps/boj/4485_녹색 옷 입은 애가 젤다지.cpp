#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 4485�� ��� �� ���� �ְ� ������?
// �з�: ���ͽ�Ʈ�� �˰���
// ����:
//		n x n ũ���� ������ �� ĭ�� ����� �־�����
//		�����¿�� ������ [0][0]���� [n-1][n-1]���� �̵���
//		���� ���� ������� ���ϴ� ����
// Ǯ��:
//		������ ��ǥ�� �ϳ��� ������
//		�����¿�θ� ����� �׷����� �����ؼ�
//		[0][0]���� ���ͽ�Ʈ�� �˰����� �����Ѵ�.
//		�׷��� [n-1][n-1]������ �ּ� ����� ��������.
#define INF 1000000000
int n;
int cave[130][130];
int dist[130][130];
bool visit[130][130];
int mr[4] = { -1, 0, 1, 0 };
int mc[4] = { 0, 1, 0, -1 };

int main() {
	int t = 1;
	while (1) {
		cin >> n;
		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> cave[i][j];
				dist[i][j] = INF;
				visit[i][j] = false;
			}

		// ���ͽ�Ʈ��
		priority_queue<pair<int, pair<int, int>>> pq; // pair<���, <���� r, ���� c>>
		dist[0][0] = cave[0][0];
		pq.push({ dist[0][0], { 0, 0 } });
		

		while (!pq.empty()) {
			int now_r = pq.top().second.first;
			int now_c = pq.top().second.second;
			int cost = -pq.top().first;
			pq.pop();

			if (visit[now_r][now_c]) continue;
			visit[now_r][now_c] = true;

			for (int i = 0; i < 4; i++) {
				if (now_r + mr[i] >= 0 && now_r + mr[i] < n && now_c + mc[i] >= 0 && now_c + mc[i] < n) {
					if (dist[now_r + mr[i]][now_c + mc[i]] > dist[now_r][now_c] + cave[now_r + mr[i]][now_c + mc[i]]) {
						dist[now_r + mr[i]][now_c + mc[i]] = dist[now_r][now_c] + cave[now_r + mr[i]][now_c + mc[i]];
						pq.push({ -dist[now_r + mr[i]][now_c + mc[i]], {now_r + mr[i], now_c + mc[i]} });
					}
				}
			}
		}

		cout << "Problem " << t << ": " << dist[n - 1][n - 1] << "\n";
		t++;
	}
}