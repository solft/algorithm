#include <iostream>
using namespace std;
// 1806�� �κ���
// �з�: �չ迭, ���� Ž��
// ����:
//		�迭���� ���ӵ� �κ��յ� �� Ư�� �� �̻��� �κ����� �ּ� ���� ���ϱ�
// Ǯ��:
//		�Է� ������ �չ迭 �����
//		ã������ ���̸� ���� Ž������ ������ ã�´�.
//		(���� ���̿��� �̻��ΰ� ã���� ���̸� ���̰�, ������ ���̸� �÷���)
int n, s;
int num[100002];

int main() {
	cin >> n >> s;

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		num[i] += num[i - 1];
	}

	if (num[n] < s) {
		cout << 0 << endl;
		return 0;
	}
		

	int left = 1;
	int right = n;
	int mid; 
	int ans = n;

	while (left <= right) {
		mid = (left + right) / 2;

		int index = 0;
		while (index + mid <= n) {
			if (num[index + mid] - num[index] >= s) {
				if (ans > mid)
					ans = mid;
				right = mid - 1;
				break;
			}
			index++;
		}

		if (right != mid - 1) {
			left = mid + 1;
		}
	}
	cout << ans << endl;
}