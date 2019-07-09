#include <iostream>
#include <queue>

using namespace std;

// 14487번 욱제는 효도쟁이야!!
// 분류: 합
// 문제:
//		모든 숫자 합에서 최댓값을 뺀 값 구하기
// 풀이:
//		입력 받으며 더하고 최댓값을 저장해두고 출력시 총 합에서 최댓값을 빼준다.
int n, cost;
int maxCost = -1;
int costSum = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cost;
		costSum += cost;
		if (maxCost < cost)
			maxCost = cost;
	}
	cout << costSum - maxCost << '\n';
}