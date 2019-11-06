#include <iostream>
using namespace std;

// 17838�� Ŀ�ǵ�
// �з�: ���ǹ�
// ����:
//		AABBABB �������� ���ϴ� ����
// Ǯ��:
//		���̰� 7�� �ƴϸ� false
//		���̰� 7�̸� �ε����� ���� ��
//		0, 1, 4 ��ġ ���ƾ��ϰ�
//		2, 3, 5, 6 ��ġ ���ƾ��ϸ�
//		���� ���� �޶�� �Ѵ�.
bool solution(string c) {
	if (c.length() != 7)
		return false;


	if (c[0] == c[1] && c[1] == c[4] && c[2] == c[3] && c[3] == c[5] && c[5] == c[6] && c[0] != c[6])
		return true;

	return false;
}

int main() {
	string command;
	int t;

	cin >> t;

	while (t--) {
		cin >> command;

		if (solution(command))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}