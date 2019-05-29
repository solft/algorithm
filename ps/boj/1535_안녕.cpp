#include <iostream>
#include <algorithm>
using namespace std;

// 1535�� �ȳ�
// �з�: DP, 0-1 Knapsack
// ����:
//		0/1 �賶 ������ �ణ ������Ų DP �����̴�.
// Ǯ��:
//		�賶 ����� 99��� �����ϰ�
//		�������� ����, �ູ�� ��ġ��� �����ؼ�
//		99������ �ѵ� ������ �ִ� �ູ�� ���ϸ� �ȴ�.
//		2���� DP�� ����
//		dp[i][j] = max(dp[i-1][j-damage[i]] + happy[i], dp[i-1][j])
//		��, (i-1)��° ��������� �ִ� ������ damage ������ �־� i��° ����� ������ ����
//		i��° ����� �������� ���� ��� �� �ִ븦 �����ϸ� �ȴ�.
int damage[22];
int happy[22];

int dp[21][101]; // dp[i][j] = i��° ������� �������� �� ü���� j ���� ���� �ִ� �ູ

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> damage[i];
	for (int i = 0; i < n; i++)
		cin >> happy[i];

	// ù���
	for (int i = 0; i < 100; i++)
		if (i + damage[0] < 100)
			dp[0][i + damage[0]] = happy[0];

	// �ι�° �������
	for (int i = 1; i < n; i++)
		for (int j = 0; j < 100; j++)
			if (j - damage[i] >= 0)
				dp[i][j] = max(dp[i - 1][j - damage[i]] + happy[i], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];

	cout << dp[n - 1][99] << endl;
}