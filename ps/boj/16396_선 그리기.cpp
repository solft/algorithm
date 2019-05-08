#include <iostream>
using namespace std;
// 16396번 선 그리기
// 분류: 구현
// 문제:
//		선의 시작과 끝이 주어지고 선을 그을때
//		최종적으로 그려진 선의 길이 구하기
// 풀이:
//		전체 좌표가 10000까지여서 배열로 잡고
//		선 그으면 1로 바꿔서
//		마지막에 1인거 다 더해줬다.
int a[10010];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		for (int j = x; j < y; j++)
			a[j] = 1;
	}

	int ans = 0;
	for (int i = 0; i <= 10000; i++)
		ans += a[i];
	printf("%d\n", ans);
}