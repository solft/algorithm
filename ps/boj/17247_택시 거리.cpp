#include <iostream>

using namespace std;

// 17247번 택시 거리
// 분류: 택시 거리
// 문제:
//		택시 거리 구하는 문제
// 풀이:
//		1이 무조건 2개 입력이므로
//		첫 1일때 저장하고
//		두번째 1일때 저장해서
//		택시 거리구한 값 출력
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a;
	bool first = true;
	int x1, y1, x2, y2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a);
			if (a) {
				if (first) {
					y1 = i;
					x1 = j;
					first = false;
				}
				else {
					y2 = i;
					x2 = j;
				}
			}
		}
	}
	printf("%d\n", abs(y1 - y2) + abs(x1 - x2));
}