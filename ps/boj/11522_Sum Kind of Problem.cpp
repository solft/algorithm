#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

// 11522번 Sum Kind of Problem
// 분류: 수학
// 문제:
//		입력 받으면 n까지의 합, n번째 홀수들의 합, n번째 짝수들의 합을 구하는 문제
// 풀이:
//		1~n = n*(n+1)/2
//		홀수 = n*n
//		짝수 = n*(n+1)
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << a << " " << b * (b + 1) / 2 << " " << b * b << " " << b * (b + 1) << "\n";
	}
}
