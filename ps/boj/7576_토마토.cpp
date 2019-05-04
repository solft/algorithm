#include <iostream>
#include <queue>
using namespace std; 
// 7576�� �丶��
// �з�: BFS, ��� �̵�
// ����:
//		��Ŀ� ���� �丶�䰡 �ְ� 1�ϸ��� �����¿��� �丶�並 �Ͱ� ���鶧
//		��� �丶�並 �Ͱ� �ϴ� ��¥ ���ϱ�
//		���� �־ �Ұ����ϸ� -1 ���
// Ǯ��:
//		���� �丶�䰡 ������ ���� �� �����Ƿ� 
//		��ó�� ������ ��ǥ�� �̸� �� �־�ΰ�
//		�ϳ��� �����鼭 BFS�� �����Ѵ�.
//		BFS�� ��ġ�� �� ��Ŀ� 0�� ������ �Ұ����̰�
//		0�� ������ ���� ū ���� ������ ���� �丶�� ��¥��
//		���� ���� ����ؾ� �ϹǷ� -1�� ���� ���ش�.
int tomato[1000][1000];
int visit[1000][1000];
int n, m;

// �������
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

int main() {
	// m = ����ĭ, n = ����ĭ
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