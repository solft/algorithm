#include <iostream>
using namespace std;
typedef long long ll;

// 17213�� ���� ����
// �з�: �ߺ� ����
// ����:
//		�ߺ� ������ ���ϴ� ����
// Ǯ��:
//		�ߺ� ���� ����� ���־���. ��� �̷��� �����ϸ�
//		���� ������ �Ѿ ������ ū �� ������ �����Ϸ��� 
//		�̷��� �����Ͽ���.
ll h(int a, int b) {
	// aHb = a+b-1Cb
	ll res = 1LL;
	int front = a + b - 1;
	int back = 2 * b <= front ? b : front - b;

	for (int i = 0; i < back; i++)
		res *= (front - i);
	for (int i = back; i > 0; i--)
		res /= i;
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << h(n, m-n) << '\n';
}