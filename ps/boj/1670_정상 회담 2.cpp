#include <iostream>
using namespace std; 

// 1670번 정상 회담2
// 문제:
//		원탁에서 현을 그릴 때 겹치지 않게 그리는 경우의 수 구하기.
// 풀이:
//		DP 사용. 식을 구해야되는데
//		n이 2a라면 아래와 같이 계산되어진다.
//		dp[a] = dp[0]*dp[a-1] + dp[1]*dp[a-2] + ... + dp[a-1]*dp[0]
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