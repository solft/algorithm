#include <iostream>
#include <algorithm>

using namespace std;

// 6443�� �ֳʱ׷�
// �з�: ����
// ����:
//		�Է� ���� ���ڿ��� �ֳʱ׷��� ����ϴ� ����
// Ǯ��:
//		next_permutation�� �̿��Ͽ� ���� Ǯ����.
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		
		do {
			cout << str << '\n';
		} while (next_permutation(str.begin(), str.end()));
	}
}