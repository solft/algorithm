#include <iostream>

using namespace std;

// 2721번 삼각수의 합
// 분류: 수학
// 문제:
//		T(n) = 1 + ... + n
//		W(n) = Sum[k=1..n; k*T(k+1)]
//		위 식을 가지고 W(n)을 구하는 문제
// 풀이:
//		위 식의 값을 리턴하는 함수를 만들고 그대로 출력해주었다.
int T(int k) {
	return k * (k + 1) / 2;
}

int W(int n) {
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result += i * T(i + 1);
	}
	return result;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		cout << W(num) << '\n';
	}
}