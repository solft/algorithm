#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<int, int> ii;
// 9205번 맥주 마시면서 걸어가기
// 분류: DFS, BFS ...
// 문제:
//		좌표가 주어지고 맨해튼 거리로 10000 이하로만 움직일 수 있을 때
//		마지막 점까지 이동 가능한지 구하는 문제
// 풀이:
//		DFS를 이용하여 이동 할 수 있을 때 까지 이동하고
//		최종적으로 마지막 점에 visit가 true면 도달 가능하다고 판단했다.
int t;
ii pos[111];
bool visit[111];
int n; // 편의점 개수

int md(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void dfs(int id, int x, int y) {
	if (visit[n + 1])
		return;
	visit[id] = true;

	for (int i = 0; i < n+2; i++) {
		if (!visit[i] && md(x, y, pos[i].first, pos[i].second) <= 1000) {
			visit[i] = true;
			dfs(i, pos[i].first, pos[i].second);
		}
	}
}

int main() {
	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n + 2; i++) {
			int x, y;
			cin >> x >> y;
			pos[i] = ii(x, y);
			visit[i] = false;
		}

		dfs(0, pos[0].first, pos[0].second);

		if (visit[n + 1])
			cout << "happy" << endl;
		else
			cout << "sad" << endl;
	}
}