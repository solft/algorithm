#include <iostream>
#include <cmath>
#include <vector>

// 4619�� ��Ʈ
// �з�: ����
// ����:
//		a^n�� �� b�� ���� ������ a�� ���ϴ� ����
// Ǯ��:
//		n�� b�� �־����� a�� �ϳ��� �÷����� ���� ����� a�� ã�´�.
using namespace std;

int main() {
	while (1) {
		int b, n;
		cin >> b >> n;
		if (b == 0 && n == 0)
			break;
		int a = 0;
		while (pow(a, n) <= b) {
			a++;
		}

		if (b - pow(a - 1, n) < pow(a, n) - b)
			cout << a - 1 << '\n';
		else
			cout << a << '\n';
	}
}