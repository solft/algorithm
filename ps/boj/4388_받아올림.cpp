#include <iostream>

using namespace std;

// 4388번 받아올림
// 분류: 구현
// 문제:
//		두 숫자 더할 때 10넘어서 다음 자리로 넘어가는 횟수를 세는 문제
// 풀이:
//		10이 넘으면 다음번 계산에 1을 더해준다.
//		마지막까지 계산하려면 두 수가 모두 0이 될 때까지 검사한다.
int main() {
	int a, b;
	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;

		int ans = 0;
		int next = 0;

		while (a != 0 || b != 0) {
			int temp = (a % 10) + (b % 10) + next;
			if (temp >= 10) {
				ans++;
				next = 1;
			}
			else {
				next = 0;
			}

			a /= 10;
			b /= 10;
		}

		cout << ans << '\n';
	}
}