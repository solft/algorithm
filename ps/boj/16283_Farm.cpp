#include <iostream>
#include <cmath>

using namespace std;

// 16283�� Farm
// �з�: ���ǹ�
// ����:
//		2�������� Ǯ��
// Ǯ��:
//		���� ������ �������� ���̽��� �� �������Ѵ�.
//		���� �ִ� ���, ���� ���, �������� ���
int main() {
	int a, b, n, w;
	cin >> a >> b >> n >> w;
	if (a == b) {
		if (w % a == 0) {
			if (w / a == n) {
				if (n == 2)
					cout << 1 << ' ' << 1 << '\n';
				else
					cout << -1 << '\n';
			}
			else
				cout << -1 << '\n';
		}
		else
			cout << -1 << '\n';
	}
	else if ((w - b * n) % (a - b) != 0 || (w - a * n) % (b - a) != 0)
		cout << -1 << '\n';
	else {
		int sheep = (w - b * n) / (a - b);
		int goat = (w - a * n) / (b - a);
		if (sheep <= 0 || goat <= 0)
			cout << -1 << '\n';
		else
			cout << sheep << ' ' << goat << '\n';
	}
}