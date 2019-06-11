#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 11005�� ���� ��ȯ 2
// �з�: ����
// ����:
//		10������ 2 ~ 36���� �� �ϳ��� ��ȯ�ϱ�
// Ǯ��:
//		2������ ���鶧 2�� ��� ������ �ָ鼭 �������� �̿��� ���ߵ���
//		b������ ���鶧 b�� ��� ������ �ָ鼭 �������� �����ϰ�
//		�Ųٷ� ������ ����Ѵ�.
stack<int> ans;
int main() {
	int n, b;
	cin >> n >> b;
	while (1) {
		int c = n % b;
		ans.push(c);
		n = n / b;
		if (n == 0)
			break;
	}
	while (!ans.empty()) {
		int c = ans.top();
		if (c >= 10)
			cout << char(c + 'A' - 10);
		else
			cout << c;
		ans.pop();
	}
	cout << '\n';
}