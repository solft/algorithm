#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 12761번 돌다리
// 분류: BFS
// 문제:
//		8가지 방법으로 이동 가능할 때 가장 적은 횟수로 특정 위치에서 해당 위치로
//		움직이는 횟수를 구하기
// 풀이:
//		queue에 다음번 이동 가능한 모든 곳을 넣어서 이동 횟수 증가시키다가
//		가장 먼저 도달할 때의 이동 횟수가 가장 빠르게 도달하는 경우이다.
int visit[100010];
int a, b, n, m;

int main() {
	cin >> a >> b >> n >> m;
	queue<pair<int, int>> pq;
	int ans = 0;
	visit[n] = 1;
	pq.push({ n, 0 });
	while (!pq.empty()) {
		
		int now = pq.front().first;
		int counter = pq.front().second;
		pq.pop();
		if (now + 1 <= 100000) {
			if (!visit[now + 1]) {
				if (now + 1 == m) {
					ans = counter + 1;
					break;
				}
				visit[now + 1] = 1;
				pq.push({ now + 1, counter + 1 });
			}
		}

		if (now - 1 >= 0) {
			if (!visit[now - 1]) {
				if (now - 1 == m) {
					ans = counter + 1;
					break;
				}
				visit[now - 1] = 1;
				pq.push({ now - 1, counter + 1 });
			}
		}

		if (now + a <= 100000) {
			if (!visit[now + a]) {
				if (now + a == m) {
					ans = counter + 1;
					break;
				}
				visit[now + a] = 1;
				pq.push({ now + a, counter + 1 });
			}
		}
		
		if (now - a >= 0) {
			if (!visit[now - a]) {
				if (now - a == m) {
					ans = counter + 1;
					break;
				}
				visit[now - a] = 1;
				pq.push({ now - a, counter + 1 });
			}
		}
		
		if (now + b <= 100000) {
			if (!visit[now + b]) {
				if (now + b == m) {
					ans = counter + 1;
					break;
				}
				visit[now + b] = 1;
				pq.push({ now + b, counter + 1 });
			}
		}

		if (now - b >= 0) {
			if (!visit[now - b]) {
				if (now - b == m) {
					ans = counter + 1;
					break;
				}
				visit[now - b] = 1;
				pq.push({ now - b, counter + 1 });
			}
		}

		if (now * a <= 100000) {
			if (!visit[now * a]) {
				if (now * a == m) {
					ans = counter + 1;
					break;
				}
				visit[now * a] = 1;
				pq.push({ now * a, counter + 1 });
			}
		}

		if (now * b <= 100000) {
			if (!visit[now * b]) {
				if (now * b == m) {
					ans = counter + 1;
					break;
				}
				visit[now * b] = 1;
				pq.push({ now * b, counter + 1 });
			}
		}
	}
	cout << ans << '\n';
}
