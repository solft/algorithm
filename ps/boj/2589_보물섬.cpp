#include <iostream>
#include <queue>
using namespace std; 
// 2589번 보물섬
// 분류: BFS
// 문제:
//		'L'칸 중 가장 최단 거리로 움직였을 때 가장 멀리까지 갈 수 있는 길이 구하기
// 풀이:
//		모든 'L'에서 BFS를 해본뒤 가장 큰 값이 제일 멀리까지 간 곳의 길이다.
char map[51][51];
int n, m;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int ans = 0;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				// 육지면 BFS 시작
				bool visit[51][51] = { false };
				queue<pair<int, int>> q;
				queue<int> dist;
				q.push(pair<int, int>(i, j));
				dist.push(0);
				visit[i][j] = true;


				while (!q.empty()) {
					pair<int, int> now = q.front();
					int currentDist = dist.front();
					q.pop();
					dist.pop();

					if (ans < currentDist)
						ans = currentDist;

					for (int k = 0; k < 4; k++) {
						if (now.first + dr[k] >= 0 && now.first + dr[k] < n && now.second + dc[k] >= 0 && now.second + dc[k] < m) {
							if (!visit[now.first + dr[k]][now.second + dc[k]] && map[now.first+dr[k]][now.second+dc[k]] == 'L') {
								q.push(pair<int, int>(now.first + dr[k], now.second + dc[k]));
								visit[now.first + dr[k]][now.second + dc[k]] = true;
								dist.push(currentDist + 1);
							}
						}
					}
				}
			}
		}
	}

	cout << ans << endl;
}