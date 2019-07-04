#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// 13986번 Gravity
// 분류: 구현
// 문제:
//		행렬이 주어지면 'o'가 '.'있는 곳을 지나칠 수 있을 때
//		중력이 있는 것 처럼 바닥으로 떨어지면 최종 상태는 어떻게 되는지 출력하는 문제
// 풀이:
//		열 하나 잡고 아래서부터 'o'를 만나면 내려갈 수 있을 때 까지 내려간다.
//		이렇게 모든 열을 반복하면 된다.
char pic[55][55];

int main() {
	int x, y;
	cin >> y >> x;
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			cin >> pic[i][j];

	// 열 별로 밑에서 부터 올라간다.
	for (int i = 0; i < x; i++) {
		for (int j = y - 1; j >= 0; j--) {
			if (pic[j][i] == 'o') {
				int drop = j;
				while (1) {
					if (drop + 1 < y && pic[drop + 1][i] == '.') {
						pic[drop][i] = '.';
						pic[drop + 1][i] = 'o';
						drop++;
					}
					else
						break;
				}
			}
		}
	}

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cout << pic[i][j];
		}
		cout << '\n';
	}
}