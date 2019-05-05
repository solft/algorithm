#include <iostream>
#include <algorithm>
#include <queue>
using namespace std; 

// 14502�� ������
// �з�: BFS, ���Ʈ����
// ����: 
//		2���� �迭�� 3���� 1�� �ٲٰ� 2�� ������ �����ؼ�
//		�����¿�� 0�� ���� 2�� �ٲ㳪�� �� ����������
//		�����ִ� 0�� ������ �ִ��� ��츦 ���ϴ� ����
// Ǯ��:
//		���Ʈ������ 1�� ������ 3���� ���ϰ�
//		�ش� ���̽��� ���� BFS�� 2�� �۶߸���
//		�����ִ� 0�� ������ ī��Ʈ�ؼ� �ִ� ���� ���Ѵ�.
int n, m;
int lab[8][8];

void printState(int arr[][8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

void bfs(int arr[][8]) {
	int mr[4] = { -1, 0, 1, 0 };
	int mc[4] = { 0, 1, 0, -1 };

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 2)
				q.push(pair<int, int>(i, j));

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (now.first + mr[i] >= 0 && now.first + mr[i] < n && now.second + mc[i] >= 0 && now.second + mc[i] < m) {
				if (arr[now.first + mr[i]][now.second + mc[i]] == 0) {
					arr[now.first + mr[i]][now.second + mc[i]] = 2;
					q.push(pair<int, int>(now.first + mr[i], now.second + mc[i]));
				}
			}
		}
	}
}

int countSafe(int arr[][8]) {
	int counter = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 0)
				counter++;
	return counter;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> lab[i][j];


	int ans = 0;
	for (int i = 0; i < m * n; i++) {
		if (lab[i / m][i % m] == 0) {
			lab[i / m][i % m] = 1;
			for (int j = i + 1; j < m * n; j++) {
				if (lab[j / m][j % m] == 0) {
					lab[j / m][j % m] = 1;
					for (int k = j + 1; k < m * n; k++) {
						if (lab[k / m][k % m] == 0) {
							lab[k / m][k % m] = 1;
							// ���⼭ �����ϰ�
							int temp[8][8];
							copy(&lab[0][0], &lab[0][0] + 64, &temp[0][0]);
							//printState(temp);
							//cout << endl;
							// BFS
							bfs(temp);
							int tempSafe = countSafe(temp);
							if (ans < tempSafe)
								ans = tempSafe;
							lab[k / m][k % m] = 0;
						}
					}
					lab[j / m][j % m] = 0;
				}
			}
			lab[i / m][i % m] = 0;
		}
	}
	cout << ans << endl;
}