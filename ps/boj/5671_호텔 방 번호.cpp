#include <iostream>

using namespace std;

// 5671번 호텔 방 번호
// 분류: 카운팅
// 문제:
//		정수 범위 내에서 동일한 숫자가 쓰이지 않는 숫자의 개수를 세는 문제
// 풀이:
//		입력 범위가 최대 1~5000이고 자리 수도 1~4이므로 전부 계산해보아도
//		시간안에 풀이 가능하다.
bool isLucky(int num) {
	int num_counter[10] = { 0, };

	int temp = num;
	while (temp != 0) {
		num_counter[temp % 10]++;
		temp /= 10;
	}

	bool result = true;
	for (int i = 0; i < 10; i++) {
		if (num_counter[i] >= 2) {
			result = false;
			break;
		}
	}

	return result;
}

int main() {
	int a, b;
	while (cin >> a >> b) {
		int ans = 0;
		for (int i = a; i <= b; i++)
			if (isLucky(i))
				ans++;
		cout << ans << '\n';
	}
}