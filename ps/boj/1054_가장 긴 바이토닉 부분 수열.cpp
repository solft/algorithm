#include <iostream>
#include <algorithm>
using namespace std;

// 11054�� ���� �� ������� �κ� ����
// �з�: DP
// ����: 
//		�־��� �������� �����ϴٰ� �پ���(������ �ص��ǰ� ���Ҹ��ص���)
//		���� �� �κ� ������ ���� ���ϴ� ����
// Ǯ��:
//		���������� �����ϴ� �κ� ���� ���� DP�� ���ϰ�
//		���������� �����ϴ� �κ� ���� ���� DP�� ���ؼ�
//		k��° ���� ���� ���� ū ������ 1 �� ���� ���� �� ������� �κ� ������ ���̰� �ȴ�.
int num[1010];
int updp[1010];
int downdp[1010];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	for (int i = 1; i <= n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++)
			if(num[i] > num[j] && max < updp[j] + 1)
				max = updp[j] + 1;
		updp[i] = max;
	} 

	for (int i = n; i >= 1; i--) {
		int max = 0;
		for (int j = n + 1; j > i; j--)
			if (num[i] > num[j] && max < downdp[j] + 1)
				max = downdp[j] + 1;
		downdp[i] = max;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (ans < updp[i] + downdp[i])
			ans = updp[i] + downdp[i];
	cout << ans - 1 << '\n';
}