#include <iostream>
using namespace std;

int n, m;
int num[100001] = { 0, };

// 11659번 구간 합 구하기 4
// 합배열 만들어 푸는 간단한 문제
// cout, cin 그냥 사용 시 시간 초과
// 그래서 printf, scanf 사용
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		num[i] += num[i - 1];
	}
	while (m--) {
		int i, j;
		scanf("%d %d", &i, &j);
		printf("%d\n", num[j] - num[i - 1]);
	}
}