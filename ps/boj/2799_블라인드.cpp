#include <iostream>
using namespace std;

// 2799번 블라인드
// 분류: 카운팅
// 문제:
//		특정 모양의 창문이 몇 개씩 있는지 세는 문제
// 풀이:
//		창문이 시작되는 i행 j열들에서 시작해서 내려가며 어느 종류의 
//		블라인드 상태인지 카운팅한다.
int m, n;
char window[600][600];

int main() {
	cin >> m >> n;
	for (int i = 0; i < 5 * n + 1; i++)
		cin >> window[0][i];
	for (int i = 1; i < 5 * m + 1; i++)
		for (int j = 0; j < 5 * n + 1; j++)
			cin >> window[i][j];

	int ans[5] = { 0, 0, 0, 0, 0 };
	// 검사할 곳
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// 검사 창문 왼쪽 위 좌표
			int wr = 5 * i + 1;
			int wc = 5 * j + 1;

			int index = 0;
			for (int c = 0; c <= 3; c++) {
				if (window[wr + c][wc] == '*')
					index++;
				else
					break;
			}
			ans[index]++;
		}
	}

	for (int i = 0; i < 5; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}