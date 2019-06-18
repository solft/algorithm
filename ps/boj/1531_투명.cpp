#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 1531�� ����
// �з�: ����
// ����:
//		�迭���� Ư�� ���� �̻��� ���� ���� ã��
// Ǯ��:
//		�Է� ����� 100 x 100���� �۾Ƽ� ���� �Է� ���� �� �������Ѻ���
//		���� �ʰ��� ���� ������ �����־���.
int picture[101][101];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int ul_x, ul_y, dr_x, dr_y;
		scanf("%d %d %d %d", &ul_x, &ul_y, &dr_x, &dr_y);

		for (int i = ul_y; i <= dr_y; i++)
			for (int j = ul_x; j <= dr_x; j++)
				picture[i][j]++;
	}

	int ans = 0;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			if (picture[i][j] > m)
				ans++;
	printf("%d\n", ans);
}