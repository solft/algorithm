#include <iostream>
using namespace std;

// 2799�� ����ε�
// �з�: ī����
// ����:
//		Ư�� ����� â���� �� ���� �ִ��� ���� ����
// Ǯ��:
//		â���� ���۵Ǵ� i�� j���鿡�� �����ؼ� �������� ��� ������ 
//		����ε� �������� ī�����Ѵ�.
int m, n;
char window[600][600];

int main() {
	cin >> m >> n;
	for (int i = 0; i < 5 * n + 1; i++)
		cin >> window[0][i];
	for (int i = 1; i < 5 * m + 1; i++)
		for (int j = 0; j < 5 * n + 1; j++)
			cin >> window[i][j];

	int ans[5] = { 0, 0, 0, 0, 0 };
	// �˻��� ��
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// �˻� â�� ���� �� ��ǥ
			int wr = 5 * i + 1;
			int wc = 5 * j + 1;

			int index = 0;
			for (int c = 0; c <= 3; c++) {
				if (window[wr + c][wc] == '*')
					index++;
				else
					break;
			}
			ans[index]++;
		}
	}

	for (int i = 0; i < 5; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}