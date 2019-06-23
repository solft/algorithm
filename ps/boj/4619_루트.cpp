#include <iostream>
#include <cmath>
#include <vector>

// 4619번 루트
// 분류: 수학
// 문제:
//		a^n들 중 b와 가장 인접한 a를 구하는 문제
// 풀이:
//		n과 b는 주어지니 a를 하나씩 늘려가며 가장 가까운 a를 찾는다.
using namespace std;

int main() {
	while (1) {
		int b, n;
		cin >> b >> n;
		if (b == 0 && n == 0)
			break;
		int a = 0;
		while (pow(a, n) <= b) {
			a++;
		}

		if (b - pow(a - 1, n) < pow(a, n) - b)
			cout << a - 1 << '\n';
		else
			cout << a << '\n';
	}
}