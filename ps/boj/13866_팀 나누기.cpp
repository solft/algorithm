#include <iostream>
#include <algorithm>
using namespace std;

// 13866�� ��������
// �з�: ����
// ����:
//		���� 4���� �� �� ¦���� ���ϰ� �� ���� �ּڰ��� ���ϴ� ����
// Ǯ��:
//		�����ؼ� ���� ū��, ���� ������ ���� ¦����
//		�߰� 2���� ¦���´�.
int main() {
	int num[4];
	for (int i = 0; i < 4; i++)
		cin >> num[i];
	sort(num, num + 4);
	cout << abs(num[3] + num[0] - num[1] - num[2]) << '\n';
}