#include <iostream>
using namespace std;
// 14579 ������ ����
// �з�: ����
// ����:
//		�־��� ������� ���ϰ� 14579�� ���� ������ ���ϱ�
// Ǯ��:
//		�״�� ����
int main() {
	int a, b;
	cin >> a >> b;
	int ans = a * (a + 1) / 2;

	while (a < b) {
		a++;
		ans *= (a * (a + 1) / 2);
		ans %= 14579;
	}
	cout << ans << endl;
}