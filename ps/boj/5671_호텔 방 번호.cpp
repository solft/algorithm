#include <iostream>

using namespace std;

// 5671�� ȣ�� �� ��ȣ
// �з�: ī����
// ����:
//		���� ���� ������ ������ ���ڰ� ������ �ʴ� ������ ������ ���� ����
// Ǯ��:
//		�Է� ������ �ִ� 1~5000�̰� �ڸ� ���� 1~4�̹Ƿ� ���� ����غ��Ƶ�
//		�ð��ȿ� Ǯ�� �����ϴ�.
bool isLucky(int num) {
	int num_counter[10] = { 0, };

	int temp = num;
	while (temp != 0) {
		num_counter[temp % 10]++;
		temp /= 10;
	}

	bool result = true;
	for (int i = 0; i < 10; i++) {
		if (num_counter[i] >= 2) {
			result = false;
			break;
		}
	}

	return result;
}

int main() {
	int a, b;
	while (cin >> a >> b) {
		int ans = 0;
		for (int i = a; i <= b; i++)
			if (isLucky(i))
				ans++;
		cout << ans << '\n';
	}
}