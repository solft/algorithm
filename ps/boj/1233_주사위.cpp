#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 1233�� �ֻ���
// �з�: �ݺ���
// ����:
//		�ֻ��� 3���� ������ ���� ���� ������ �ֻ��� ���� ���ϴ� ����
// Ǯ��:
//		���� ���� 20*20*30 �� �ݺ����̿��� ���Ʈ������ �� ���ߴ�.
int dice[100];

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			for (int k = 1; k <= c; k++)
				dice[i + j + k]++;

	int m = 0;
	int ans = 0;

	for (int i = 3; i <= a + b + c; i++) {
		if (dice[i] > m) {
			m = dice[i];
			ans = i;
		}
	}

	cout << ans << '\n';
}