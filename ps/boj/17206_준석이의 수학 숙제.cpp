#include <iostream>
using namespace std;

// 17206번 준석이의 수학 숙제
// 분류: 수학
// 문제:
//		숫자 n 이하의 (3의 배수) + (7의 배수) 구하기
// 풀이:
//		(3의배수) + (7의배수) - (21의배수)
int n[100001];

int solution(int a) {
	// (항의개수*(초항+막항))/2
	int tree = ((a / 3) * (3 + 3 * (a / 3))) / 2;
	int seven = ((a / 7) * (7 + 7 * (a / 7))) / 2;
	int twentyone = ((a / 21) * (21 + 21 * (a / 21))) / 2;
	return tree + seven - twentyone;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		cin >> n[i];

	for (int i = 0; i < t; i++)
		cout << solution(n[i]) << '\n';
}
