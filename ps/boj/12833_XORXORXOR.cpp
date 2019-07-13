#include <iostream>
#include <stack>
using namespace std;

// 12833번 XORXORXOR
// 분류: XOR
// 문제:
//		A에 XOR B 연산을 C번 하고난 뒤의 결과를 구하는 문제
// 풀이:
//		XOR은 결합 법칙이 성립하므로 B끼리 XOR 하면 짝수면 다 없어지고
//		홀수면 B 하나만 남는다. 이를 이용해 계산하면 된다.
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (c % 2 == 0)
		cout << a << '\n';
	else {
		int t = a ^ b;
		cout << t << '\n';
	}
}