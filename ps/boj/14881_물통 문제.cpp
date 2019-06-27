#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 14881�� ���� ����
// �з�: GCD
// ����:
//		�뷮 a, b¥�� �������� c�� ����� �ִ��� ���� ����
// Ǯ��:
//		gcd(a, b)�� ������� a, b�� ����� �ִ� �뷮���̴�.
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int g = a > b ? gcd(a, b) : gcd(b, a);
		if (c <= max(a, b) && c % g == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}