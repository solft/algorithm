#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// 17266�� ��ο� ���ٸ�
// �з�: ū �� ã��
// ����:
//		ó���� �������� �״�� �߰��� ���ݸ�ŭ�� ���̵� �� ���� ū ���� ã��
// Ǯ��:
//		ù�Է°� �������Է��� �״�� ������ �߰��� ��� Ȧ���� ��� 1 ũ�� ¦���� ��� �״��
int main() {
	int ans = 0;
	int n, m;
	cin >> n >> m;
	int before = 0;
	for (int i = 0; i < m; i++) {
		int pos;
		cin >> pos;

		if (i == 0) {
			if (ans < pos)
				ans = pos;
			before = pos;
		}
		else {
			if (ans < (pos - before + 1) / 2)
				ans = (pos - before + 1) / 2;
			before = pos;
		}
	}

	if (ans < n - before)
		ans = n - before;
	cout << ans << '\n';
}
