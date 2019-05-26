#include <iostream>
#include <algorithm>
using namespace std;

// 17216번 가장 큰 감소 부분 수열
// 분류: DP
// 문제:
//		수열이 주어지고 감소하는 부분 수열 중 합이 가장 큰 값을 구하는 문제
// 풀이:
//		num[j] > num[i] 이면 추가 가능하므로
//		dp[i] = max(dp[i], dp[j] + num[i]) 테스트를 거쳐 더해 나간다
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