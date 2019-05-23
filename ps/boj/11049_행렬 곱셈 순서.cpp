#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 11049번 행렬 곱셈 순서
// 분류: DP
// 문제:
//		행렬들이 주어졌을 때 가장 적은 연산 횟수로 곱셈을 마치는 수를 구하는 문제
// 풀이:
//		dp[i][j] = i번째 행렬에서 j번째 행렬 곱의 최소 횟수
//		dp[i][j] = (k는 i부터 j-1까지)MIN(dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j])
typedef long long ll;
#define MAX 2000000000
ll p[550];
ll dp[550][550];

ll sol(int a, int b) {
	if (dp[a][b] != MAX)
		return dp[a][b];
	else {
		int m = MAX;
		for (int i = 0; a + i < b; i++) {
			int temp = sol(a, a + i) + sol(a + i + 1, b) + p[a - 1] * p[a + i] * p[b];
			if (m > temp)
				m = temp;
		}
		dp[a][b] = m;
		return dp[a][b];
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		p[i] = a;
		if (i == n - 1)
			p[i + 1] = b;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = MAX;
			if (i == j)
				dp[i][j] = 0;
		}
	}

	cout << sol(1, n) << '\n';
}
