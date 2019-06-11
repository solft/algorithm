#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 11005번 진법 변환 2
// 분류: 진법
// 문제:
//		10진법을 2 ~ 36진법 중 하나로 변환하기
// 풀이:
//		2진법을 만들때 2로 계속 나누어 주면서 나머지를 이용해 구했듯이
//		b진법을 만들때 b로 계속 나누어 주면서 나머지를 저장하고
//		거꾸로 빼내며 출력한다.
stack<int> ans;
int main() {
	int n, b;
	cin >> n >> b;
	while (1) {
		int c = n % b;
		ans.push(c);
		n = n / b;
		if (n == 0)
			break;
	}
	while (!ans.empty()) {
		int c = ans.top();
		if (c >= 10)
			cout << char(c + 'A' - 10);
		else
			cout << c;
		ans.pop();
	}
	cout << '\n';
}