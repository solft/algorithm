#include <iostream>

using namespace std;

// 17247�� �ý� �Ÿ�
// �з�: �ý� �Ÿ�
// ����:
//		�ý� �Ÿ� ���ϴ� ����
// Ǯ��:
//		1�� ������ 2�� �Է��̹Ƿ�
//		ù 1�϶� �����ϰ�
//		�ι�° 1�϶� �����ؼ�
//		�ý� �Ÿ����� �� ���
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a;
	bool first = true;
	int x1, y1, x2, y2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a);
			if (a) {
				if (first) {
					y1 = i;
					x1 = j;
					first = false;
				}
				else {
					y2 = i;
					x2 = j;
				}
			}
		}
	}
	printf("%d\n", abs(y1 - y2) + abs(x1 - x2));
}