#include <iostream>
#include <set>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

// 2251번 물통
// 분류: BFS
// 문제:
//		물통 a, b, c가 있고 c만 꽉차있을 때 요리조리 물을 옮겨서
//		a에 0리터의 물이 있을 때 c에 몇리터의 물을 만들 수 있는지 
//		가능한 모든 경우를 구하는 문제
// 풀이:
//		첫 케이스 {0, 0, c}에서 시작하여 a, b, c 모든 물병에서
//		다른 물병으로 옮길 수 있고 방문한 적이 없을 시 물을 옮겨
//		큐에 추가하고 이를 반복해서 큐가 빌때 까지 계속 진행한다.
//		큐에서 빼낸값을 검사할 때 a가 0이라면 답에 추가한다.
bool visit[201][201][201];
queue<tuple<int, int, int>> q;
set<int> ans;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	q.push({ 0, 0, c });
	ans.insert(c);
	visit[0][0][c] = true;
	while (!q.empty()) {
		int nowA = get<0>(q.front());
		int nowB = get<1>(q.front());
		int nowC = get<2>(q.front());
		q.pop();

		if (nowA == 0)
			ans.insert(nowC);
			

		// nowA를 붓는 경우
		if (nowA != 0) {
			if (nowA + nowB <= b) {
				if (!visit[0][nowA + nowB][nowC]) {
					visit[0][nowA + nowB][nowC] = true;
					q.push({ 0, nowA + nowB, nowC });
				}
			}
			else {
				if (!visit[nowA - (b - nowB)][b][nowC]) {
					visit[nowA - (b - nowB)][b][nowC] = true;
					q.push({ nowA - (b - nowB), b, nowC });
				}
			}

			if (nowA + nowC <= c) {
				if (!visit[0][nowB][nowA + nowC]) {
					visit[0][nowB][nowA + nowC] = true;
					q.push({ 0, nowB, nowA + nowC });
				}
			}
			else {
				if (!visit[nowA - (c - nowC)][nowB][c]) {
					visit[nowA - (c - nowC)][nowB][c] = true;
					q.push({ nowA - (c - nowC), nowB, c });
				}
			}
		}

		// nowB를 붓는 경우
		if (nowB != 0) {
			if (nowB + nowA <= a) {
				if (!visit[nowA + nowB][0][nowC]) {
					visit[nowA + nowB][0][nowC] = true;
					q.push({ nowA + nowB, 0, nowC });
				}
			}
			else {
				if (!visit[a][nowB - (a - nowA)][nowC]) {
					visit[a][nowB - (a - nowA)][nowC] = true;
					q.push({ a, nowB - (a - nowA), nowC });
				}
			}

			if (nowB + nowC <= c) {
				if (!visit[nowA][0][nowB + nowC]) {
					visit[nowA][0][nowB + nowC] = true;
					q.push({ nowA, 0, nowB + nowC });
				}
			}
			else {
				if (!visit[nowA][nowB - (c - nowC)][c]) {
					visit[nowA][nowB - (c - nowC)][c] = true;
					q.push({ nowA, nowB - (c - nowC), c });
				}
			}
		}

		// nowC를 붓는 경우
		if (nowC != 0) {
			if (nowA + nowC <= a) {
				if (!visit[nowA + nowC][nowB][0]) {
					visit[nowA + nowC][nowB][0] = true;
					q.push({ nowA + nowC, nowB, 0 });
				}
			}
			else {
				if (!visit[a][nowB][nowC - (a - nowA)]) {
					visit[a][nowB][nowC - (a - nowA)] = true;
					q.push({ a, nowB, nowC - (a - nowA) });
				}
			}

			if (nowB + nowC <= b) {
				if (!visit[nowA][nowB + nowC][0]) {
					visit[nowA][nowB + nowC][0] = true;
					q.push({ nowA, nowB + nowC, 0 });
				}
			}
			else {
				if (!visit[nowA][b][nowC - (b - nowB)]) {
					visit[nowA][b][nowC - (b - nowB)] = true;
					q.push({ nowA, b, nowC - (b - nowB) });
				}
			}
		}
	}

	for (auto c : ans)
		cout << c << ' ';
	cout << '\n';
}