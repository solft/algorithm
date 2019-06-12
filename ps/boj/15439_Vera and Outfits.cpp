#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 15439번 Vera and Outfits
// 분류: 수학
// 문제:
//		n가지 색 상의 n가지 색 바지있을 때 다른 색으로 매칭 시키는 경우의 수
// 풀이:
//		n * (n-1)
int main() {
	int n;
	cin >> n;
	cout << n * (n - 1) << '\n';
}