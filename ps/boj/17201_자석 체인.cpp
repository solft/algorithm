#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 17201�� �ڼ� ü��
// �з�: �������� ��
// ����:
//		���� ���� ���� ������ ������ No, ������ Yes
// Ǯ��:
//		���� ���� ������ No, ������ �� �ٸ��� Yes
int main() {
	int n;
	cin >> n;
	string magnet;
	cin >> magnet;
	char before = magnet[0];
	for (int i = 1; i < 2 * n; i++) {
		if (before == magnet[i]) {
			cout << "No\n";
			return 0;
		}
		before = magnet[i];
	}
	cout << "Yes\n";
	return 0;
}