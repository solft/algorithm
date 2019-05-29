#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 2000000000

// 1660번 캡틴 이다솜
// 분류: DP
// 문제:
//		대포알[i] = 대포알[i-1] + (i*(i+1))/2 의 규칙으로 있을 때
//		n개를 대포알 개수로 덩어리 지을 때 가장 최소 덩어리 개수를 찾는 문제
// 풀이:
//		대포알 개수를 동전 값어치라 생각하고 동전 DP처럼 풀면 된다.
vector<int> canon;
vector<int> dp;

int oneToN(int n) {
	return n * (n + 1) / 2;
}

int main() {
	canon.resize(122);
	

	int n;
	cin >> n;
	dp.resize(n + 1, MAX);
	dp[0] = 0;

	canon[1] = 1;
	for (int i = 2; i <= 121; i++) {
		canon[i] = canon[i - 1] + oneToN(i);
	}
	
	for (int i = 0; i <= n; i++) {
		for (auto k : canon) {
			if (i - k >= 0)
				dp[i] = min(dp[i], dp[i - k] + 1);
			else
				break;
		}
	}

	cout << dp[n] << '\n';
}