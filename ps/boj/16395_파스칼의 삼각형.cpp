#include <iostream>
using namespace std; 
typedef long long ll;

// 16395번 파스칼의 삼각형
// 문제:
//		파스칼의 삼각형에서 n행의 k번째 수 구하는 문제
// 풀이:
//		(n-1)C(k-1) 구하는 문제다.
//		입력값이 작으므로 재귀와 DP를 이용한 이항 계수 구하는 방법으로 풀었다.
ll dp[40][40] = { 0, };

ll C(int x, int y) {
	if (y == 0 || x == y)
		return dp[x][y] = ll(1);
	else if (dp[x][y] != 0)
		return dp[x][y];
	else 
		return dp[x][y] = C(x - 1, y - 1) + C(x - 1, y);
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << C(n-1, k-1) << endl;
}