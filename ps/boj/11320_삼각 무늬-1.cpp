#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 11320번 삼각 무늬 - 1
// 분류: 수학
// 문제:
//		큰 삼각형에 작은 삼각형이 몇 개 있는지 구하는 문제
// 풀이:
//		a/b가 행의 수이고 각 행은 1부터 시작하는 홀수로 구성되어있다.
//		그래서 홀수의 합인 (a/b)*(a/b)다.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << (a / b) * (a / b) << '\n';
	}
}