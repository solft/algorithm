#include <iostream>
#include <stack>
using namespace std;

// 14682번 Shifty Sum
// 분류: 수학
// 문제:
//		n이 주어지고 n + n0 + n00 + ... n(k개의 0)을 구하기
// 풀이:
//		n + n*10 + n*100 + ... + n*10^k 를 구한다.
int solution(int n, int k) {
	int result = 0;
	int shift = 1;
	while (k >= 0) {
		result += shift * n;
		shift *= 10;
		k--;
	}
	return result;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << solution(n, k) << '\n';
}