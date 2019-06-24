#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 12845번 모두의 마블
// 분류: 최댓값
// 문제:
//		숫자들을 합쳐가며 하나로 만들때 더한 값들의 최댓값 구하기
// 풀이:
//		최댓값 * (n-1) + 나머지
int n;
int card[1001];
int ans = 0;

int main() {
	cin >> n;
	int max_val = 0;
	int max_idx = 0;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
		if (max_val < card[i]) {
			max_val = card[i];
			max_idx = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (max_idx == i)
			continue;
		ans += card[i];
	}
	ans += (n - 1) * max_val;
	cout << ans << '\n';
}