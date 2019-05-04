#include <iostream>
#include <queue>
using namespace std; 
// 7576번 토마토
// 분류: BFS, 행렬 이동
// 문제:
//		행렬에 익은 토마토가 있고 1일마다 상하좌우의 토마토를 익게 만들때
//		모든 토마토를 익게 하는 날짜 구하기
//		벽도 있어서 불가능하면 -1 출력
// 풀이:
//		익은 토마토가 여러개 있을 수 있으므로 
//		맨처음 시작할 좌표를 미리 다 넣어두고
//		하나씩 빼내면서 BFS를 진행한다.
//		BFS를 마치고 난 행렬에 0이 있으면 불가능이고
//		0이 없으면 가장 큰 값이 마지막 익은 토마토 날짜고
//		지난 날을 출력해야 하므로 -1을 따로 해준다.
int tomato[1000][1000];
int visit[1000][1000];
int n, m;

// 상우하좌
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int main() {
	// m = 가로칸, n = 세로칸
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> tomato[i][j];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (tomato[i][j] == 1) {
				q.push(pair<int, int>(i, j));
			}
		}
	}

	int date = 1;
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		date = tomato[now.first][now.second] + 1;
		for (int i = 0; i < 4; i++) {
			if (now.first + dr[i] >= 0 && now.first + dr[i] < m && now.second + dc[i] >= 0 && now.second + dc[i] < n) {
				if (tomato[now.first + dr[i]][now.second + dc[i]] == 0) {
					tomato[now.first + dr[i]][now.second + dc[i]] = date;
					q.push(pair<int, int>(now.first + dr[i], now.second + dc[i]));
				}
			}
		}
	}


	bool impossible = false;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (tomato[i][j] == 0) {
				impossible = true;
				break;
			}
			if (tomato[i][j] > ans)
				ans = tomato[i][j];
		}
		if (impossible)
			break;
	}
	if (impossible)
		cout << -1 << endl;
	else
		cout << ans - 1 << endl;
}