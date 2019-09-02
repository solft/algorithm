#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1018�� ü���� �ٽ� ĥ�ϱ�
// �з�: ���Ʈ����
// ����:
//		�־��� ü���ǿ��� 8x8 ������ �̾Ƴ���
//		���� ���� �������� �ϼ��� ü���� ����� ���� ���� ���ϴ� ����
// Ǯ��:
//		8x8ĭ¥���� �ɰ��� �� ���� ������ �ʿ����� �� �����ش�.
int n, m;
char chess[55][55];

int sol(int l, int r) {
	int sum = l + r;
	int w = 0;
	int b = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((sum + i + j) % 2 == 0) {
				if (chess[l + i][r + j] == 'W')
					b++;
				else if (chess[l + i][r + j] == 'B')
					w++;
			}
			else {
				if (chess[l + i][r + j] == 'W')
					w++;
				else if (chess[l + i][r + j] == 'B')
					b++;
			}
		}
	}

	if (w < b)
		return w;
	else
		return b;
}

int main() {

	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> chess[i][j];


	int ans = 1000000000;

	for (int i = 0; i + 7 < n; i++) {
		for (int j = 0; j + 7 < m; j++) {
			int temp = sol(i, j);
			ans = min(ans, temp);
		}
	}
	cout << ans << '\n';
}