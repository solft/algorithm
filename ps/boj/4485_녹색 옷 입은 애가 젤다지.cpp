#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 4485번 녹색 옷 입은 애가 젤다지?
// 분류: 다익스트라 알고리즘
// 문제:
//		n x n 크기의 동굴에 각 칸에 비용이 주어지면
//		상하좌우로 움직여 [0][0]에서 [n-1][n-1]까지 이동시
//		가장 적은 비용합을 구하는 문제
// 풀이:
//		각각의 좌표를 하나의 정점에
//		상하좌우로만 연결된 그래프로 생각해서
//		[0][0]에서 다익스트라 알고리즘을 시작한다.
//		그러면 [n-1][n-1]까지의 최소 비용이 구해진다.
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

		// 다익스트라
		priority_queue<pair<int, pair<int, int>>> pq; // pair<비용, <정점 r, 정점 c>>
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