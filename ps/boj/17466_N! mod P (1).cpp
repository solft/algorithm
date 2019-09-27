#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// 17466번 N! mod P (1)
// 분류: 수학
// 문제:
//		N! mod P를 구하는 문제
// 풀이:
//		계산해서 구한다.
//		빠른 풀이는 찾지 못했다.
int main() {
	long long n, p;
	cin >> n >> p;

	long long sol = 1;
	for (int i = n; i > 1; i--) {
		sol *= i;
		sol %= p;
	}

	cout << sol << '\n';
}