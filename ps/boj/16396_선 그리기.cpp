#include <iostream>
using namespace std;
// 16396�� �� �׸���
// �з�: ����
// ����:
//		���� ���۰� ���� �־����� ���� ������
//		���������� �׷��� ���� ���� ���ϱ�
// Ǯ��:
//		��ü ��ǥ�� 10000�������� �迭�� ���
//		�� ������ 1�� �ٲ㼭
//		�������� 1�ΰ� �� �������.
int a[10010];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		for (int j = x; j < y; j++)
			a[j] = 1;
	}

	int ans = 0;
	for (int i = 0; i <= 10000; i++)
		ans += a[i];
	printf("%d\n", ans);
}