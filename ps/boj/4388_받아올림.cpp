#include <iostream>

using namespace std;

// 4388�� �޾ƿø�
// �з�: ����
// ����:
//		�� ���� ���� �� 10�Ѿ ���� �ڸ��� �Ѿ�� Ƚ���� ���� ����
// Ǯ��:
//		10�� ������ ������ ��꿡 1�� �����ش�.
//		���������� ����Ϸ��� �� ���� ��� 0�� �� ������ �˻��Ѵ�.
int main() {
	int a, b;
	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;

		int ans = 0;
		int next = 0;

		while (a != 0 || b != 0) {
			int temp = (a % 10) + (b % 10) + next;
			if (temp >= 10) {
				ans++;
				next = 1;
			}
			else {
				next = 0;
			}

			a /= 10;
			b /= 10;
		}

		cout << ans << '\n';
	}
}