#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 1531번 투명
// 분류: 구현
// 문제:
//		배열에서 특정 숫자 이상인 곳의 개수 찾기
// 풀이:
//		입력 사이즈가 100 x 100으로 작아서 직접 입력 범위 다 증가시켜보고
//		기준 초과인 곳의 개수를 세어주었다.
int picture[101][101];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int ul_x, ul_y, dr_x, dr_y;
		scanf("%d %d %d %d", &ul_x, &ul_y, &dr_x, &dr_y);

		for (int i = ul_y; i <= dr_y; i++)
			for (int j = ul_x; j <= dr_x; j++)
				picture[i][j]++;
	}

	int ans = 0;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			if (picture[i][j] > m)
				ans++;
	printf("%d\n", ans);
}