#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<int, int> ii;
// 9205�� ���� ���ø鼭 �ɾ��
// �з�: DFS, BFS ...
// ����:
//		��ǥ�� �־����� ����ư �Ÿ��� 10000 ���Ϸθ� ������ �� ���� ��
//		������ ������ �̵� �������� ���ϴ� ����
// Ǯ��:
//		DFS�� �̿��Ͽ� �̵� �� �� ���� �� ���� �̵��ϰ�
//		���������� ������ ���� visit�� true�� ���� �����ϴٰ� �Ǵ��ߴ�.
int t;
ii pos[111];
bool visit[111];
int n; // ������ ����

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