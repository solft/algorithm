#include <iostream>
using namespace std;
typedef long long ll;

// 17213번 과일 서리
// 분류: 중복 조합
// 문제:
//		중복 조합을 구하는 문제
// 풀이:
//		중복 조합 계산을 해주었다. 사실 이렇게 구현하면
//		숫자 범위를 넘어갈 위험이 큰 데 간단히 구현하려고 
//		이렇게 구현하였다.
ll h(int a, int b) {
	// aHb = a+b-1Cb
	ll res = 1LL;
	int front = a + b - 1;
	int back = 2 * b <= front ? b : front - b;

	for (int i = 0; i < back; i++)
		res *= (front - i);
	for (int i = back; i > 0; i--)
		res /= i;
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << h(n, m-n) << '\n';
}