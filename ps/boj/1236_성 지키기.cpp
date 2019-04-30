#include <iostream>
using namespace std; 
// 1236�� ����Ű��
// ����:
//		row�� col�� ��� �Ѹ��� ������ �־�ߵǴµ�
//		�־��� ���¿��� ������ �����Ϸ��� �� ���� �߰��Ǿ�� �ϴ��� ���ϴ� ����
// Ǯ��:
//		�� row�� col�� �� ������ Ȯ���ϰ�
//		�켱 row�� col ��� 0�� ��ġ�� �߰��� ��
//		row�� 0�� ��, col�� 0�� ���� �߰�����
//		������ ������Ű�� �� �� �߰��� �ο��� ���� �ȴ�.
char castle[51][51];
int row[51] = { 0, };
int col[51] = { 0, };

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> castle[i][j];

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (castle[i][j] == 'X')
				row[i]++, col[j]++;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (row[i] == 0 && col[j] == 0)
				ans++, row[i]++, col[j]++;

	for (int i = 0; i < n; i++)
		if (row[i] == 0)
			ans++, row[i]++;

	for (int j = 0; j < m; j++)
		if (col[j] == 0)
			ans++, col[j]++;
	cout << ans << endl;
}