#include <iostream>
#include <queue>

using namespace std;

// 14487�� ������ ȿ�����̾�!!
// �з�: ��
// ����:
//		��� ���� �տ��� �ִ��� �� �� ���ϱ�
// Ǯ��:
//		�Է� ������ ���ϰ� �ִ��� �����صΰ� ��½� �� �տ��� �ִ��� ���ش�.
int n, cost;
int maxCost = -1;
int costSum = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cost;
		costSum += cost;
		if (maxCost < cost)
			maxCost = cost;
	}
	cout << costSum - maxCost << '\n';
}