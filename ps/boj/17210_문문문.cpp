#include <iostream>
using namespace std;
typedef long long ll;

// 17210번 문문문
// 분류: 규칙 찾기
// 문제:
//		문을 여는 규칙이 주어지고 규칙에 맞게 여는 방법을 출력하거나
//		출력하지 못하면 "Love is open door"를 출력하는 문제
// 풀이:
//		6 이상이면 무조건 "Love is open door"이고
//		6 미만이면 번갈아 열면 된다.
int main() {
	ll n;
	cin >> n;
	int door;
	cin >> door;

	if (n >= 6LL) {
		cout << "Love is open door" << '\n';
	}
	else {
		for (ll i = 2LL; i <= n; i++) {
			door = 1 - door;
			cout << door << '\n';
		}
	}
}