#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 2630번 색종이 만들기
// 분류: 분할정복
// 문제:
//		정사각형 모양의 같은 숫자 뭉치가 몇 개 인지 세는 문제
// 풀이:
//		특정 사이즈가 전부 같으면 카운트 증가시키고
//		다르면 분할해서 반복한다.
int n;
int paper[130][130];
int blue = 0;
int white = 0;

void solution(int y, int x, int size) {

	int now = paper[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (paper[i][j] != now) {
				now = -1;
				break;
			}
		}
		if (now == -1)
			break;
	}

	if (now == 0)
		white++;
	else if (now == 1)
		blue++;
	else {
		int half = size / 2;
		solution(y, x, half);
		solution(y + half, x, half);
		solution(y, x + half, half);
		solution(y + half, x + half, half);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];

	solution(0, 0, n);
	cout << white << '\n' << blue << '\n';
}