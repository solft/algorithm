#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

// 11522�� Sum Kind of Problem
// �з�: ����
// ����:
//		�Է� ������ n������ ��, n��° Ȧ������ ��, n��° ¦������ ���� ���ϴ� ����
// Ǯ��:
//		1~n = n*(n+1)/2
//		Ȧ�� = n*n
//		¦�� = n*(n+1)
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << a << " " << b * (b + 1) / 2 << " " << b * b << " " << b * (b + 1) << "\n";
	}
}
