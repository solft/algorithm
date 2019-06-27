#include <iostream>
#include <set>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

// 2251�� ����
// �з�: BFS
// ����:
//		���� a, b, c�� �ְ� c�� �������� �� �丮���� ���� �Űܼ�
//		a�� 0������ ���� ���� �� c�� ����� ���� ���� �� �ִ��� 
//		������ ��� ��츦 ���ϴ� ����
// Ǯ��:
//		ù ���̽� {0, 0, c}���� �����Ͽ� a, b, c ��� ��������
//		�ٸ� �������� �ű� �� �ְ� �湮�� ���� ���� �� ���� �Ű�
//		ť�� �߰��ϰ� �̸� �ݺ��ؼ� ť�� ���� ���� ��� �����Ѵ�.
//		ť���� �������� �˻��� �� a�� 0�̶�� �信 �߰��Ѵ�.
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
			

		// nowA�� �״� ���
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

		// nowB�� �״� ���
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

		// nowC�� �״� ���
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