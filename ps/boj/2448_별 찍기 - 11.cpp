#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

// 2448번 별 찍기 - 11
// 분류: 규칙 찾기
// 문제:
//		규칙에 맞게 별 찍기
// 풀이:
//		한 케이스에서 3번의 작은 케이스로 나눠지고
//		최소 케이스는 크기 3짜리이므로
//		크기 3이 나올 때 까지 재귀로 진행해서 전체 그림에 저장시켰다.
char star[7000][7000];

void makeStar(int size, int y, int x) {
	if (size == 3) {
		star[y][x] = '*';

		star[y + 1][x - 1] = '*';
		star[y + 1][x] = ' ';
		star[y + 1][x + 1] = '*';

		star[y + 2][x - 2] = '*';
		star[y + 2][x - 1] = '*';
		star[y + 2][x] = '*';
		star[y + 2][x + 1] = '*';
		star[y + 2][x + 2] = '*';
	}
	else {
		makeStar(size / 2, y, x);
		makeStar(size / 2, y + size / 2, x - size / 2);
		makeStar(size / 2, y + size / 2, x + size / 2);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n * 2; j++)
			star[i][j] = ' ';
	makeStar(n, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n * 2; j++)
			cout << star[i][j];
		cout << '\n';
	}
}