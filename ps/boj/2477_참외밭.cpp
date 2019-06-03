#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

// 2477번 참외밭
// 분류: 수학
// 문제:
//		ㄱ이 4방향으로 돌아간 형태의 땅이 주어질 때
//		면적을 구하는 문제
// 풀이:
//		세로로 가장 긴 변과 가로로 가장 긴 변을 구하고
//		긴 변 인덱스에서 3번째로 나타나는 변이 짧은 변들이므로
//		이를 이용해 큰 사각형에서 작은 사각형 빼서 넓이를 구한다
pair<int, int> side[6];

int main() {
	int k;
	cin >> k;

	int long_x = 0;
	int x_index = 0;
	int long_y = 0;
	int y_index = 0;

	int short_x = 0;
	int short_y = 0;

	for (int i = 0; i < 6; i++) {
		cin >> side[i].first >> side[i].second;
		if (side[i].first <= 2) { // 가로
			if (long_x < side[i].second) {
				long_x = side[i].second;
				x_index = i;
			}
		}
		else if (side[i].first > 2) { // 세로
			if (long_y < side[i].second) {
				long_y = side[i].second;
				y_index = i;
			}
		}
	}

	short_y = side[(x_index + 3) % 6].second;
	short_x = side[(y_index + 3) % 6].second;

	cout << ((long_x * long_y) - (short_x * short_y)) * k << '\n';
}
