#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

// 2447번 별 찍기 - 10
// 분류: 규칙 찾기, Divide and Conquer
// 문제:
//		규칙에 맞게 별 찍기
// 풀이:
//		한 케이스에서 9방향으로 만들어 나가는거 같아서 
//		9번 함수 호출하는 재귀로 풀었다.
char star[6561][6561];

void makeStar(int size, int state, int y, int x) {
	if (size == 1) {
		if (state == 1)
			star[y][x] = '*';
		else if (state == 2)
			star[y][x] = ' ';
	}
	else {
		if (state == 1) {
			makeStar(size / 3, 1, y, x);
			makeStar(size / 3, 1, y, x + size / 3);
			makeStar(size / 3, 1, y, x + (size / 3) * 2);

			makeStar(size / 3, 1, y + size / 3, x);
			makeStar(size / 3, 2, y + size / 3, x + size / 3);
			makeStar(size / 3, 1, y + size / 3, x + (size / 3) * 2);

			makeStar(size / 3, 1, y + (size / 3) * 2, x);
			makeStar(size / 3, 1, y + (size / 3) * 2, x + size / 3);
			makeStar(size / 3, 1, y + (size / 3) * 2, x + (size / 3) * 2);
		}
		else if (state == 2) {
			makeStar(size / 3, 2, y, x);
			makeStar(size / 3, 2, y, x + size / 3);
			makeStar(size / 3, 2, y, x + size / 3 * 2);

			makeStar(size / 3, 2, y + size / 3, x);
			makeStar(size / 3, 2, y + size / 3, x + size / 3);
			makeStar(size / 3, 2, y + size / 3, x + (size / 3) * 2);

			makeStar(size / 3, 2, y + (size / 3) * 2, x);
			makeStar(size / 3, 2, y + (size / 3) * 2, x + size / 3);
			makeStar(size / 3, 2, y + (size / 3) * 2, x + (size / 3) * 2);
		}
	}
}

int main() {
	int n;
	cin >> n;
	makeStar(n, 1, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << star[i][j];
		cout << '\n';
	}
}