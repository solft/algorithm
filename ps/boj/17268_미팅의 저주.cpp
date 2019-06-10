#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 17268번 미팅의 저주
// 분류: DP, 수학
// 문제:
//		원에서 점들이 짝수개 주어지고 점들을 잇는 선을 그릴때 겹치지 않게 그리는 경우의 수
// 풀이:
//		1670번 정상 회담2 문제와 완전 똑같다.
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