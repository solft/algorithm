#include <iostream>
using namespace std;
// 14563 ������
// �з�: ����
// ����:
//		������, ������, ���׼� ���ϴ� ����
// Ǯ��:
//		�Է��� ���� �۾Ƽ� �Ҽ��� ���� �ȱ��ϰ� �׳� ���� �˻��ߴ�.
int num[1001];

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		cin >> num[i];

	for (int i = 0; i < t; i++) {
		int ans = 0;

		for (int j = 1; j < num[i]; j++) {
			if (num[i] % j == 0)
				ans += j;
		}
		if (ans > num[i])
			cout << "Abundant" << endl;
		else if (ans < num[i])
			cout << "Deficient" << endl;
		else
			cout << "Perfect" << endl;
	}
}