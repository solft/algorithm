#include <iostream>

using namespace std;

// 2721�� �ﰢ���� ��
// �з�: ����
// ����:
//		T(n) = 1 + ... + n
//		W(n) = Sum[k=1..n; k*T(k+1)]
//		�� ���� ������ W(n)�� ���ϴ� ����
// Ǯ��:
//		�� ���� ���� �����ϴ� �Լ��� ����� �״�� ������־���.
int T(int k) {
	return k * (k + 1) / 2;
}

int W(int n) {
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result += i * T(i + 1);
	}
	return result;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		cout << W(num) << '\n';
	}
}