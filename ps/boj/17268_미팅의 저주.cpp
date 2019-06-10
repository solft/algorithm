#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 17268�� ������ ����
// �з�: DP, ����
// ����:
//		������ ������ ¦���� �־����� ������ �մ� ���� �׸��� ��ġ�� �ʰ� �׸��� ����� ��
// Ǯ��:
//		1670�� ���� ȸ��2 ������ ���� �Ȱ���.
long long dp[5001];

int main() {
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	int n;
	cin >> n;
	n /= 2;

	for (int i = 3; i <= n; i++) {
		long long temp = 0;
		for (int j = 0; j < i; j++) {
			temp += dp[j] * dp[i - 1 - j];
			temp %= 987654321;
		}
		dp[i] = temp;
	}
	cout << dp[n] << endl;
}