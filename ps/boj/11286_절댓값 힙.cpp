#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 11286번 절댓값 힙
// 분류: 힙
// 문제:
//		절댓값이 작고 절댓값이 같다면 작은 값이 먼저 나오는 힙을 만드는 문제
// 풀이:
//		STL의 priority_queue를 이용해서 그대로 구현하였다.
int main() {
	priority_queue<pair<int, int>> apq;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int d;
		scanf("%d", &d);
		if (d == 0) {
			if (apq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", apq.top().first * apq.top().second);
				apq.pop();
			}
		}
		else if (d > 0) {
			apq.push({ -d, -1 });
		}
		else if (d < 0) {
			apq.push({ d, 1 });
		}
	}
}