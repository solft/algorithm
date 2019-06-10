#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 17251번 힘 겨루기
// 분류: 최댓값 찾기
// 문제:
//		최댓값의 개수와 위치를 찾아서 경우를 따지는 문제
// 풀이:
//		최댓값이 유일하게 한 개일 경우 최댓값의 위치가 절반해서 왼쪽에 있으면
//		Red 팀이 이길 확률이 크고 반대면 Blue 팀이 이길 확률이 크다.
//		최댓값이 2군데 이상에서 발생하면 가장 왼쪽 최댓값 위치와 가장 오른쪽 최댓값 위치를 구해서
//		가장 왼쪽 최댓값 왼쪽 부분이 항상 Blue가 이기는 곳
//		가장 오른족 최댓값 오른쪽 부분이 항상 Red가 이기는 곳
//		둘 사이는 비기는 곳으로 해서 구한다.
int person[1000010];
int main() {
	int n;
	cin >> n;
	int max_power = 0;
	int power_left = 0;
	int power_right = -1;
	for (int i = 0; i < n; i++) {
		cin >> person[i];

		if (max_power == person[i])
			power_right = i;
		else if (max_power < person[i]) {
			max_power = person[i];
			power_left = i;
			power_right = -1;
		}
	}

	// 가장 쎈사람이 1명일 경우
	if (power_right == -1) {
		if (power_left * 2 < n)
			cout << "R\n";
		else
			cout << "B\n";
	}
	else { // 가장 쎈사람이 2명 이상일 경우
		int red_win = n - 1 - power_right;
		int blue_win = power_left;

		if (red_win > blue_win)
			cout << "R\n";
		else if (red_win < blue_win)
			cout << "B\n";
		else
			cout << "X\n";
	}
}