#include <iostream>
using namespace std;

// 17202�� �ڵ��� ��ȣ ����
// �з�: �ݺ���
// ����:
//		������ �迭 ���س����ٰ� ������ ���� 2�ڸ� ����ϴ� ����
// Ǯ��:
//		�ݺ������� �ϳ��� �ٿ������� ���� �����ٰ� 2�� ���� ����� ����Ѵ�
int main() {
	int phone[20];

	for (int i = 1; i <= 8; i++) {
		char p;
		cin >> p;
		phone[2 * i - 1] = p - '0';
	}
		
	for (int i = 1; i <= 8; i++) {
		char p;
		cin >> p;
		phone[2 * i] = p - '0';
	}
		
	int size = 16;
	while (size > 2) {
		for (int i = 2; i <= size; i++)
			phone[i - 1] = (phone[i - 1] + phone[i])%10;
		size--;
	}
	cout << char(phone[1]+'0') << char(phone[2]+'0') << '\n';
}
