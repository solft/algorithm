#include <iostream>
using namespace std;
// 14579 덧셈과 곱셈
// 분류: 수학
// 문제:
//		주어진 방식으로 곱하고 14579로 나눈 나머지 구하기
// 풀이:
//		그대로 구현
int main() {
	int a, b;
	cin >> a >> b;
	int ans = a * (a + 1) / 2;

	while (a < b) {
		a++;
		ans *= (a * (a + 1) / 2);
		ans %= 14579;
	}
	cout << ans << endl;
}