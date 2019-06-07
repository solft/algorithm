#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 17263번 Sort 마스터 배지훈
// 분류: 가장 큰 원소 찾기
// 문제:
//		숫자 입력받아서 가장 큰 원소를 출력하는 문제
// 풀이:
//		입력 받으면서 최댓값을 저장하고 출력한다.
priority_queue<int> pq;

int main() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (ans < a)
			ans = a;
	}
	printf("%d\n", ans);
}
