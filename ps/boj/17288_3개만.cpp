#include <iostream>

using namespace std;

// 17288�� 3����!
// �з�: ī����
// ����:
//		���ڰ� 1�� �����ϴ� ���ӵ� ��Ȯ�� ���� 3¥�� ���� �κ��� �� �� �ִ��� ���ϴ� ����
// Ǯ��:
//		���ڰ� �����ϸ� count�� �÷����� 3�� �� ������ 1 ������Ų��.
//		������ �κи� �� �� �� ������ �ش�.
int main() {
	string num_str;
	cin >> num_str;

	int before = num_str[0] - '0';
	int count = 1;
	int ans = 0;
	for (unsigned int i = 1; i < num_str.size(); i++) {
		int num = num_str[i] - '0';

		
		if (before + 1 == num) {
			count++;
			before = num;
		}
		else {
			if (count == 3)
				ans++;
			count = 1;
			before = num;
		}
	}

	if (count == 3)
		ans++;

	cout << ans << '\n';
}