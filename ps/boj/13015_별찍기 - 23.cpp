#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 13015�� �����-23
// �з�: �����, ��Ģ ã��
// ����:
//		X ��� �����
// Ǯ��:
//		�������� ������ ����Ѵ�.��
int main() {
	int n;
	cin >> n;
	// ���κ�
	for (int i = 0; i < n; i++)
		cout << '*';
	for (int i = 0; i < (n - 2) * 2 + 1; i++)
		cout << ' ';
	for (int i = 0; i < n; i++)
		cout << '*';
	cout << '\n';

	for (int i = 1; i <= n - 2; i++) {
		for (int j = 0; j < i; j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++)
			cout << ' ';
		cout << '*';
		for (int j = (n-2-i)*2+1; j > 0; j--)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++)
			cout << ' ';
		cout << '*';
		cout << '\n';
	}

	// �߰� �κ�
	for (int i = 0; i < n - 1; i++)
		cout << ' ';
	cout << '*';
	for (int i = 0; i < n - 2; i++)
		cout << ' ';
	cout << '*';
	for (int i = 0; i < n - 2; i++)
		cout << ' ';
	cout << '*';
	cout << '\n';


	// �Ʒ� �κ�
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 0; j < n - 1 - i; j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < (i-1)*2+1; j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++)
			cout << ' ';
		cout << '*';
		cout << '\n';
	}

	for (int i = 0; i < n; i++)
		cout << '*';
	for (int i = 0; i < (n - 2) * 2 + 1; i++)
		cout << ' ';
	for (int i = 0; i < n; i++)
		cout << '*';
	cout << '\n';
}