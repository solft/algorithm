#include <iostream>
#include <stack>
using namespace std;

// 12833�� XORXORXOR
// �з�: XOR
// ����:
//		A�� XOR B ������ C�� �ϰ� ���� ����� ���ϴ� ����
// Ǯ��:
//		XOR�� ���� ��Ģ�� �����ϹǷ� B���� XOR �ϸ� ¦���� �� ��������
//		Ȧ���� B �ϳ��� ���´�. �̸� �̿��� ����ϸ� �ȴ�.
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (c % 2 == 0)
		cout << a << '\n';
	else {
		int t = a ^ b;
		cout << t << '\n';
	}
}