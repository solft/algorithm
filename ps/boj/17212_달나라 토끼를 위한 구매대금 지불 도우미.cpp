#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 17212�� �޳��� �䳢�� ���� ���Ŵ�� ���� �����
// �з�: DP
// ����:
//		dp ���� ����
// Ǯ��:
//		dp[money] = min(dp[money], dp[money - �����׼�] + 1);
#define MAX 100001
vector<int> dp;
int coin[4] = { 1, 2, 5, 7 };

int main() {
	int n;
	cin >> n;
	dp.assign(n + 1, MAX);
	dp[0] = 0;
	for (int money = 1; money <= n; money++)
		for (int i = 0; i < 4; i++)
			if(money-coin[i] >= 0)
				dp[money] = min(dp[money], dp[money - coin[i]] + 1);
	cout << dp[n] << '\n';
}