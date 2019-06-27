#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 16561번 3의 배수
// 분류: 수학
// 문제:
//		3의 배수를 3의 배수 3개로 나누어 표현하는 방법의 수 찾기
// 풀이:
//		3의 배수 n이 들어오면 3H(n/3-3)을 구하는 문제다.
int main() {
	int n;
	cin >> n;
	int a = (n / 3) - 3;
	cout << (a + 2) * (a + 1) / 2 << '\n';
}