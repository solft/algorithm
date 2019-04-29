typedef long long ll;
// ���� ���(Binomial coefficient), 
// ����(Combination), 
// �Ľ�Į�� �ﰢ��(Pascal's triangle)

// 1. xCy ž�ٿ� DP�� ���ϱ�
ll dp[100][100] = { 0, };
ll combination(int x, int y) {
	if (y == 0 || x == y)
		return dp[x][y] = 1LL;
	else if (dp[x][y] != 0)
		return dp[x][y];
	else
		return dp[x][y] = C(x - 1, y - 1) + C(x - 1, y);
}

// 2. ���� x¥�� �Ľ�Į�� �ﰢ�� �����
ll pascalTriangle[101][101];
void makePascal(int x) {
	// �׵θ� ���� 1�� �����
	pascalTrianble[0][0] = 1;
	for (int i = 1; i <= x; i++) {
		pascalTriangle[i][0] = 1;
		pascalTriangle[i][i] = 1;
	}
	// ���� ä���
	for (int i = 2; i <= x; i++)
		for (int j = 1; j < i; j++)
			pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
}
// ���� pascalTriangle[x][y] = xCy ��.

// 3. �丣�� �������� ���� ���� ��� ������ ���ϱ�
#include <cstdio>
#include <algorithm>
#define P 1000000007LL
ll fac[4000001], n, k, inv[4000001]; // inv[x]�� x�� inverse�� �ƴ� x!�� inverse

// ���� ������ �̿��Ͽ� x^y ���ϱ�
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
	// nCn �̰ų� nC0 �� ���
	if (n == k || !k)
		return 1LL;

	fac[0] = 1;
	fac[1] = 1;
	for (int i = 1; i <= 4000000; i++)
		fac[i] = (fac[i - 1] * i) % P; // factorial ��ó��
	inv[4000000] = power(fac[4000000], P - 1); // �丣�� �������� �̿��Ͽ� fac(400��)�� inverse�� ����
	for (int i = 4000000 - 1; i >= 0; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % P; // inverse(fac(i)) = inverse(fac(i+1))*(i+1)
	// �� O(N+logP) �ð��� ��ó���� ����
	// ��ó���� ������ ������ � ������ ���͵� ����ð��� ���� ����� ��� ����
	ll r = (fac[n] * inv[n - k]) % P;
	r = (r * inv[k]) % P;
	return r;
}