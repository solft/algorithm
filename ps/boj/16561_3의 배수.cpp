#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 16561�� 3�� ���
// �з�: ����
// ����:
//		3�� ����� 3�� ��� 3���� ������ ǥ���ϴ� ����� �� ã��
// Ǯ��:
//		3�� ��� n�� ������ 3H(n/3-3)�� ���ϴ� ������.
int main() {
	int n;
	cin >> n;
	int a = (n / 3) - 3;
	cout << (a + 2) * (a + 1) / 2 << '\n';
}