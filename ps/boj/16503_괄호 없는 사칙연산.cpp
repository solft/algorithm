#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

// 16503번 괄호 없는 사칙연산
// 분류: 구현
// 문제:
//		간단한 수식이 주어지고 앞 먼저 계산할때랑 뒤먼저 계산할때 결과중에
//		작은거 먼저 출력하고 큰거 뒤에 출력하는 문제
// 풀이:
//		두 번 계산해서 작은 거 먼저 출력하고 큰 거 나중에 출력한다.
int calculate(int a, int b, char o) {
	if (o == '+') {
		return a + b;
	}
	else if (o == '*') {
		return a * b;
	}
	else if (o == '/') {
		return a / b;
	}
	else if (o == '-') {
		return a - b;
	}
}

int main() {
	int a, b, c;
	char o1, o2;
	cin >> a >> o1 >> b >> o2 >> c;
	int ans1 = calculate(a, b, o1);
	ans1 = calculate(ans1, c, o2);
	int ans2 = calculate(b, c, o2);
	ans2 = calculate(a, ans2, o1);
	if (ans1 > ans2)
		cout << ans2 << '\n' << ans1 << '\n';
	else
		cout << ans1 << '\n' << ans2 << '\n';
}