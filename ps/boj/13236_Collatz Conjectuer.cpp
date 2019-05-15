#include <iostream>
using namespace std;

// 13236�� Collatz Conjecture
// �з�: ����
// ����:
//		n�� ¦���� �� 2�� ������
//		n�� Ȧ���� �� 3���ϰ� 1���ϱ�
//		�ϴ� ������ 1�� ���� �� ���� ���
// Ǯ��:
//		������ ���� ���Ǵ�� �����ϸ� �ȴ�.
int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 1;
		return 0;
	}


	while (1) {
		cout << n << " ";
		if (n == 2)
			break;

		if (n % 2 == 0)
			n /= 2;
		else
			n = 3 * n + 1;
	}
	cout << 1;
}