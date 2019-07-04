#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

// 1731�� �߷�
// �з�: ����
// ����:
//		�Է¹��� ������ �������� ������� �˾� ���߰� ���� ���� ���ϴ� ����
// Ǯ��:
//		�� ���� ������ ���踦 2�� ���ؼ� ���� or ��� �˾Ƴ���
//		�������׿� ������ ������ ���ش�.
int num[55];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	
	bool isMultiple = false;
	int next = 0;

	if (num[1] - num[0] == num[n - 1] - num[n - 2]) { // ����
		next = num[1] - num[0];
	}
	else if (num[1] / num[0] == num[n - 1] / num[n - 2]) { // ���
		isMultiple = true;
		next = num[1] / num[0];
	}

	if (isMultiple)
		cout << next * num[n - 1] << '\n';
	else
		cout << next + num[n - 1] << '\n';
}