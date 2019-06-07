#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 12761�� ���ٸ�
// �з�: BFS
// ����:
//		8���� ������� �̵� ������ �� ���� ���� Ƚ���� Ư�� ��ġ���� �ش� ��ġ��
//		�����̴� Ƚ���� ���ϱ�
// Ǯ��:
//		queue�� ������ �̵� ������ ��� ���� �־ �̵� Ƚ�� ������Ű�ٰ�
//		���� ���� ������ ���� �̵� Ƚ���� ���� ������ �����ϴ� ����̴�.
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
