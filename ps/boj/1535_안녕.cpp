#include <iostream>
#include <algorithm>
using namespace std;

// 1535번 안녕
// 분류: DP, 0-1 Knapsack
// 문제:
//		0/1 배낭 문제를 약간 변형시킨 DP 문제이다.
// 풀이:
//		배낭 사이즈가 99라고 생각하고
//		데미지가 무게, 행복이 가치라고 생각해서
//		99데미지 한도 내에서 최대 행복을 구하면 된다.
//		2차원 DP를 만들어서
//		dp[i][j] = max(dp[i-1][j-damage[i]] + happy[i], dp[i-1][j])
//		즉, (i-1)번째 사람까지의 최대 값에서 damage 여유가 있어 i번째 사람을 선택할 경우와
//		i번째 사람을 선택하지 않은 경우 중 최대를 저장하면 된다.
int damage[22];
int happy[22];

int dp[21][101]; // dp[i][j] = i번째 사람까지 생각했을 때 체력이 j 깎일 때의 최대 행복

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> damage[i];
	for (int i = 0; i < n; i++)
		cin >> happy[i];

	// 첫사람
	for (int i = 0; i < 100; i++)
		if (i + damage[0] < 100)
			dp[0][i + damage[0]] = happy[0];

	// 두번째 사람부터
	for (int i = 1; i < n; i++)
		for (int j = 0; j < 100; j++)
			if (j - damage[i] >= 0)
				dp[i][j] = max(dp[i - 1][j - damage[i]] + happy[i], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];

	cout << dp[n - 1][99] << endl;
}