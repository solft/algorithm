#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 14761번 FizzBuzz
// 분류: 구현
// 풀이:
//		문제에 주어진대로 구현
int main() {
	int a, b, n;
	cin >> a >> b >> n;

	for (int i = 1; i <= n; i++) {
		bool p = false;
		if (i % a == 0) {
			p = true;
			cout << "Fizz";
		}
		if (i % b == 0) {
			p = true;
			cout << "Buzz";
		}
		if (!p)
			cout << i;
		cout << '\n';
	}
}
