#include <iostream>

using namespace std;

// 9094�� ������ ȣ���
// �з�: �ݺ���
// ����:
//		(a^2+b^2+m)/(ab)�� ������ �� (a, b) ã�� ����. 0 < a < b < n
// Ǯ��:
//		������ 100 �����̹Ƿ� ���Ʈ������ ���� ���غ���.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		int ans = 0;
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (((i * i) + (j * j) + m) % (i * j) == 0)
					ans++;

		cout << ans << '\n';
	}
}