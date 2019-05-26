#include <iostream>
#include <algorithm>
using namespace std;

// 17216�� ���� ū ���� �κ� ����
// �з�: DP
// ����:
//		������ �־����� �����ϴ� �κ� ���� �� ���� ���� ū ���� ���ϴ� ����
// Ǯ��:
//		num[j] > num[i] �̸� �߰� �����ϹǷ�
//		dp[i] = max(dp[i], dp[j] + num[i]) �׽�Ʈ�� ���� ���� ������
int num[1001];
int dp[1001];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> num[i];
		dp[i] = num[i];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (num[j] > num[i])
				dp[i] = max(dp[i], dp[j] + num[i]);

	int ans = 0;
	for (int i = 0; i < n; i++)
		if (ans < dp[i])
			ans = dp[i];
	cout << ans << '\n';
}