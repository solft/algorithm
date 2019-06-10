#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 17251�� �� �ܷ��
// �з�: �ִ� ã��
// ����:
//		�ִ��� ������ ��ġ�� ã�Ƽ� ��츦 ������ ����
// Ǯ��:
//		�ִ��� �����ϰ� �� ���� ��� �ִ��� ��ġ�� �����ؼ� ���ʿ� ������
//		Red ���� �̱� Ȯ���� ũ�� �ݴ�� Blue ���� �̱� Ȯ���� ũ��.
//		�ִ��� 2���� �̻󿡼� �߻��ϸ� ���� ���� �ִ� ��ġ�� ���� ������ �ִ� ��ġ�� ���ؼ�
//		���� ���� �ִ� ���� �κ��� �׻� Blue�� �̱�� ��
//		���� ������ �ִ� ������ �κ��� �׻� Red�� �̱�� ��
//		�� ���̴� ���� ������ �ؼ� ���Ѵ�.
int person[1000010];
int main() {
	int n;
	cin >> n;
	int max_power = 0;
	int power_left = 0;
	int power_right = -1;
	for (int i = 0; i < n; i++) {
		cin >> person[i];

		if (max_power == person[i])
			power_right = i;
		else if (max_power < person[i]) {
			max_power = person[i];
			power_left = i;
			power_right = -1;
		}
	}

	// ���� ������ 1���� ���
	if (power_right == -1) {
		if (power_left * 2 < n)
			cout << "R\n";
		else
			cout << "B\n";
	}
	else { // ���� ������ 2�� �̻��� ���
		int red_win = n - 1 - power_right;
		int blue_win = power_left;

		if (red_win > blue_win)
			cout << "R\n";
		else if (red_win < blue_win)
			cout << "B\n";
		else
			cout << "X\n";
	}
}