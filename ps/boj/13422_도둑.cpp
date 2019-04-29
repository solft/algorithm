#include <iostream>
using namespace std;

// 13422�� ����
// ����:
//		���� �迭�� �κ����� threshold �̸��� ���� ������ ���ϴ� ����
// Ǯ��:
//		�켱 �κ����� �ʿ��ϴ� �չ迭�� ����� ���̵��� �����Ͽ�
//		���� ������ �� ù ���Һ��� ���� ��
//		���ϱ� ���� �κ��� ���۰� �� �κ��� �������� �ʴ� �κк��� ���ϰ�
//		��踦 �����ϴ� �κ��� ��Ģ�� ã�� �����ָ� �ȴ�.
//		���ϸ鼭 ī�����ص� �Ǵµ� �׳� �� ���ϰ� ī�����ߴ�.
//		�Ѱ��� ������ ���� ����� ���� ���� �����̹Ƿ�
//		n == m�� ��� ��ü ���̽��� 1�����ų� 0������ �� üũ����� �Ѵ�.

int t;
// n = ���� ����, 
// m = �������� ��ĥ ���� ����, 
// k = �����ġ threshold
int n, m, k; 
int house[100000];
// money[i] = house[i] ~ house[i - m + 1]���� ���� ��
// money[m - 1] = house[0]���� house[m - 1]
int money[100000]; 

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int ans = 0;
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &house[i]);
		// ó�� ������ �� money[m-1] ���ϱ�
		money[m - 1] = 0;
		for (int i = 0; i < m; i++)
			money[m - 1] += house[i];
		// ���� m == n �� ��� ����� ���� 1���� �ƴϸ� 0������
		if (m == n) {
			if (money[m - 1] < k)
				printf("1\n");
			else
				printf("0\n");
			continue;
		}
		// money[m] ~ money[n-1]���� ���ϱ�
		for (int i = m; i < n; i++)
			money[i] = money[i - 1] - house[i - m] + house[i];
		// money[0] ~ money[m-2]���� ���ϱ�
		for (int i = 0; i < m - 1; i++)
			money[i] = money[(n + i - 1) % n] + house[i] - house[(n + i - m) % n];
		for (int i = 0; i < n; i++)
			if (money[i] < k)
				ans++;
		printf("%d\n", ans);
	}
}