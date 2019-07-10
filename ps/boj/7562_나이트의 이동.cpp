#include <iostream>
#include <queue>

using namespace std;

// 7562번 나이트의 이동
// 분류: BFS
// 문제:
//		나이트가 몇 번의 이동만에 원하는 곳에 도달하는지 횟수를 세는 문제
// 풀이:
//		나이트가 한 번 이동 시 이동한 곳을 큐에 넣고 
//		계속 반복해서 몇 번째에 도달하는지 카운트한다.
int visit[303][303];
int t, s;
int startR, startC;
int destR, destC;
pair<int, int> mv[8] = { {-2,1}, {-1,2}, {1, 2}, {2, 1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1} };

int main() {
	cin >> t;
	while (t--) {
		cin >> s;
		for (int i = 0; i < s; i++)
			for (int j = 0; j < s; j++)
				visit[i][j] = 0;

		cin >> startR >> startC;
		cin >> destR >> destC;

		bool findAns = false;
		queue<pair<int, int>> q;
		queue<int> counter;
		q.push({ startR, startC });
		counter.push(0);
		visit[startR][startC] = 1;

		while (!q.empty()) {
			int nowR = q.front().first;
			int nowC = q.front().second;
			int nowCounter = counter.front();

			if (nowR == destR && nowC == destC) {
				cout << nowCounter << '\n';
				break;
			}
			q.pop();
			counter.pop();

			for (int i = 0; i < 8; i++) {
				if (nowR + mv[i].first >= 0 && nowR + mv[i].first < s && nowC + mv[i].second >= 0 && nowC + mv[i].second < s) {
					if (visit[nowR + mv[i].first][nowC + mv[i].second] == 0) {
						if (nowR + mv[i].first == destR && nowC + mv[i].second == destC) {
							cout << nowCounter + 1 << '\n';
							findAns = true;
							break;
						}
						visit[nowR + mv[i].first][nowC + mv[i].second] = 1;
						q.push({ nowR + mv[i].first, nowC + mv[i].second });
						counter.push(nowCounter + 1);
					}
				}
			}
			if (findAns)
				break;
		}
	}
}