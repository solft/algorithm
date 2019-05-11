#include <iostream>
using namespace std;
// 14563 완전수
// 분류: 수학
// 문제:
//		완전수, 부족수, 과잉수 구하는 문제
// 풀이:
//		입력의 수가 작아서 소수를 따로 안구하고 그냥 전부 검사했다.
int num[1001];

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		cin >> num[i];

	for (int i = 0; i < t; i++) {
		int ans = 0;

		for (int j = 1; j < num[i]; j++) {
			if (num[i] % j == 0)
				ans += j;
		}
		if (ans > num[i])
			cout << "Abundant" << endl;
		else if (ans < num[i])
			cout << "Deficient" << endl;
		else
			cout << "Perfect" << endl;
	}
}