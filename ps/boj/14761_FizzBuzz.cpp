#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 14761�� FizzBuzz
// �з�: ����
// Ǯ��:
//		������ �־������ ����
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
