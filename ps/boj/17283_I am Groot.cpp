#include <iostream>
#include <cmath>

using namespace std;

// 17283번 I am Groot
// 분류: 수학
// 문제:
//		일정 비율로 줄면서 5 이하가 될 때 까지 2배씩 곱한 합을 구하는 문제
// 풀이:
//		소수점 관련해서 내림이므로 여기에 주의해서 푼다.
int main() {
	double l, r;
	cin >> l >> r;
	int ans = 0;
	int branch = 2;
	while (1) {
		l *= (r / 100);
		l = floor(l);
		if (l <= 5.0)
			break;
		ans += branch * int(l);
		branch *= 2;
	}

	cout << ans << '\n';
}