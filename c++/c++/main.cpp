#include <iostream>
using namespace std;

int n, m;
int num[100001] = { 0, };

// 11659�� ���� �� ���ϱ� 4
// �չ迭 ����� Ǫ�� ������ ����
// cout, cin �׳� ��� �� �ð� �ʰ�
// �׷��� printf, scanf ���
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		num[i] += num[i - 1];
	}
	while (m--) {
		int i, j;
		scanf("%d %d", &i, &j);
		printf("%d\n", num[j] - num[i - 1]);
	}
}