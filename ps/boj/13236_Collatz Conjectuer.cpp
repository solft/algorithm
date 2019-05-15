#include <iostream>
using namespace std;

// 13236번 Collatz Conjecture
// 분류: 구현
// 문제:
//		n이 짝수일 때 2로 나누기
//		n이 홀수일 때 3곱하고 1더하기
//		하는 순열을 1이 나올 때 까지 출력
// 풀이:
//		문제에 나온 조건대로 구현하면 된다.
int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 1;
		return 0;
	}


	while (1) {
		cout << n << " ";
		if (n == 2)
			break;

		if (n % 2 == 0)
			n /= 2;
		else
			n = 3 * n + 1;
	}
	cout << 1;
}