#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 14568번 2017 연세대학교 프로그래밍 경시대회
// 분류: 경우의 수
// 문제:
//		택희 + 남규 + 영훈 = n 이고
//		택희는 짝수, 남규 >= 영훈 + 2 인 경우의 수 구하기
// 풀이:
//		경우의 수를 직접 세어준다.
int main() {
	int n;
	cin >> n;
	int ans = 0;
	int young, taek;
	taek = 2;
	while (n - taek >= 4) {
		young = 1;
		while (n - taek - young >= young + 2) {
			ans++;
			young++;
		}
		taek += 2;
	}
	cout << ans << '\n';
}