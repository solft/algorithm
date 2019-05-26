#include <iostream>
using namespace std;

// 17211번 좋은 날 싫은 날
// 분류: 확률
// 문제:
//		오늘 상태에서 다음날의 기분이 어떻게 바뀌지에 대한 확률이 주어지고
//		n일 뒤의 기분의 확률을 구하는 문제
// 풀이:
//		(i+1)일에 기분 좋을 확률 = i일에 기분 좋을 확률 * 기분좋음->기분좋음일 확률 + i일에 기분 안 좋을 확률 * 기분안좋음->기분좋음일 확률
//		(i+1)일에 기분 안 좋을 확률 = i일에 기분 좋을 확률 * 기분좋음->기분안좋음일 확률 + i일에 기분 안 좋을 확률 * 기분안좋음->기분안좋은일 확률
int main() {
	int n, feeling;
	cin >> n >> feeling;
	double happy_happy, happy_sad, sad_happy, sad_sad;
	cin >> happy_happy >> happy_sad >> sad_happy >> sad_sad;
	double mood[2][101];

	mood[feeling][0] = 1.0;
	mood[1 - feeling][0] = 0.0;

	for (int i = 0; i < n; i++) {
		mood[0][i + 1] = mood[0][i] * happy_happy + mood[1][i] * sad_happy;
		mood[1][i + 1] = mood[0][i] * happy_sad + mood[1][i] * sad_sad;
	}

	cout << int(mood[0][n]*1000 + 0.5) << '\n';
	cout << int(mood[1][n]*1000 + 0.5) << '\n';
}