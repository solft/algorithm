#include <iostream>
#include <cmath>

using namespace std;

// 15726번 이칙연산
// 분류: 수학
// 문제:
//		곱하고 나눈거랑 나누고 곱한거랑 둘 중에 뭐가 더 큰지 구하는 문제
// 풀이:
//		곱하고 나눈 값과 나누고 곱한 값을 비교해서
//		큰 값을 int 형으로(내림해서) 출력한다.
int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double md = a * b / c;
	double dm = a / b * c;
	if (md > dm)
		cout << int(md) << '\n';
	else
		cout << int(dm) << '\n';
}