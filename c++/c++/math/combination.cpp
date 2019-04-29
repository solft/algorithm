typedef long long ll;
// 이항 계수(Binomial coefficient), 
// 조합(Combination), 
// 파스칼의 삼각형(Pascal's triangle)

// 1. xCy 탑다운 DP로 구하기
ll dp[100][100] = { 0, };
ll combination(int x, int y) {
	if (y == 0 || x == y)
		return dp[x][y] = 1LL;
	else if (dp[x][y] != 0)
		return dp[x][y];
	else
		return dp[x][y] = C(x - 1, y - 1) + C(x - 1, y);
}

// 2. 높이 x짜리 파스칼의 삼각형 만들기
ll pascalTriangle[101][101];
void makePascal(int x) {
	// 테두리 전부 1로 만들기
	pascalTrianble[0][0] = 1;
	for (int i = 1; i <= x; i++) {
		pascalTriangle[i][0] = 1;
		pascalTriangle[i][i] = 1;
	}
	// 내부 채우기
	for (int i = 2; i <= x; i++)
		for (int j = 1; j < i; j++)
			pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
}
// 이제 pascalTriangle[x][y] = xCy 다.

// 3. 페르마 소정리를 용한 이항 계수 빠르게 구하기
#include <cstdio>
#include <algorithm>
#define P 1000000007LL
ll fac[4000001], n, k, inv[4000001]; // inv[x]는 x의 inverse가 아닌 x!의 inverse

// 분할 정복을 이용하여 x^y 구하기
ll power(ll x, ll y) {
	ll ret = 1;
	while (y > 0) {
		if (y % 2) {
			ret *= x;
			ret %= P;
		}
		x *= x;
		x %= P;
		y /= 2;
	}
	return ret;
}

// Fermat's little Theorem
ll FlT(int n, int k) {
	// nCn 이거나 nC0 일 경우
	if (n == k || !k)
		return 1LL;

	fac[0] = 1;
	fac[1] = 1;
	for (int i = 1; i <= 4000000; i++)
		fac[i] = (fac[i - 1] * i) % P; // factorial 전처리
	inv[4000000] = power(fac[4000000], P - 1); // 페르마 소정리를 이용하여 fac(400만)의 inverse를 구함
	for (int i = 4000000 - 1; i >= 0; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % P; // inverse(fac(i)) = inverse(fac(i+1))*(i+1)
	// 총 O(N+logP) 시간에 전처리를 끝냄
	// 전처리가 끝났기 때문에 어떤 쿼리가 들어와도 상수시간에 이항 계수를 계산 가능
	ll r = (fac[n] * inv[n - k]) % P;
	r = (r * inv[k]) % P;
	return r;
}