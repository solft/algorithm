#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 11320�� �ﰢ ���� - 1
// �з�: ����
// ����:
//		ū �ﰢ���� ���� �ﰢ���� �� �� �ִ��� ���ϴ� ����
// Ǯ��:
//		a/b�� ���� ���̰� �� ���� 1���� �����ϴ� Ȧ���� �����Ǿ��ִ�.
//		�׷��� Ȧ���� ���� (a/b)*(a/b)��.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << (a / b) * (a / b) << '\n';
	}
}