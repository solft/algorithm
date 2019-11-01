#include <iostream>
using namespace std;

// 17608번 막대기
// 분류: 카운팅
// 문제:
//		높이가 다양한 막대가 일렬로 세워져 있을 때,
//		오른쪽에서 몇 개의 막대가 보이는지 세는 문제
// 풀이:
//		오른쪽부터 가장 긴 막대를 정하면서 카운팅 한다.
int stick[100010];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stick[i];
	}

	int rightHigh = stick[n - 1];
	int ans = 1;

	for (int i = n - 2; i >= 0; i--) {
		if (rightHigh < stick[i]) {
			ans++;
			rightHigh = stick[i];
		}
	}

	cout << ans << '\n';
}