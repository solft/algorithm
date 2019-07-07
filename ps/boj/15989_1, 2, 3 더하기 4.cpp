#include <iostream>

using namespace std;

// 15989번 1, 2, 3 더하기 4
// 분류: 규칙
// 문제:
//		1, 2, 3의 합으로 나타낼 수 있는 방법의 수 찾기
// 풀이:
//		1, 2 둘로 나타낼수 있는 경우의 수는 2로 나누고 1 더한 값이다.
//		이를 3을 몇 번 쓰느냐에 따라 다 더해주면 된다.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = 0;
		while (n >= 0) {
			ans += (n / 2 + 1);
			n -= 3;
		}

		cout << ans << '\n';
	}
}