#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 17265번 나의 인생에는 수학과 함께
// 분류: DP?
// 문제:
//		그래프를 오른쪽 or 아래쪽으로 따라가며 계산한 결과의 최대,최소 구하는 문제
// 풀이:
//		계산 시작할 위치(r, c 합이 짝수인 곳)에서 가능한 방향으로 연산을 한 뒤
//		다음 위치의 값을 업데이트 한다. (최대, 최소로) 그러면 n-1열 n-1행에 
//		최대, 최소가 저장된다.
int n;
char world[5][5];
int max_val[5][5];
int min_val[5][5];

int eval(int a, char ope, int b) {
	if (ope == '+')
		return a + b;
	else if (ope == '-')
		return a - b;
	else if (ope == '*')
		return a * b;
	else
		return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> world[i][j];
			if ((i + j) % 2 == 0)
				min_val[i][j] = 1000000000;
				max_val[i][j] = -1000000000;
		}
	
	min_val[0][0] = max_val[0][0] = world[0][0] - '0';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i * 2; j++) {
			int r = j;
			int c = 2 * i - j;
			
			// rr 계산
			if (c + 2 < n) {
				max_val[r][c + 2] = max(max_val[r][c + 2], eval(max_val[r][c], world[r][c + 1], world[r][c + 2] - '0'));
				min_val[r][c + 2] = min(min_val[r][c + 2], eval(min_val[r][c], world[r][c + 1], world[r][c + 2] - '0'));
			}
			// rd, dr 계산
			if (r + 1 < n && c + 1 < n) {
				int max_temp = max(eval(max_val[r][c], world[r][c + 1], world[r + 1][c + 1] - '0'),
					eval(max_val[r][c], world[r + 1][c], world[r + 1][c + 1] - '0'));
				max_val[r + 1][c + 1] = max(max_val[r + 1][c + 1], max_temp);
				int min_temp = min(eval(min_val[r][c], world[r][c + 1], world[r + 1][c + 1] - '0'),
					eval(min_val[r][c], world[r + 1][c], world[r + 1][c + 1] - '0'));
				min_val[r + 1][c + 1] = min(min_val[r + 1][c + 1], min_temp);
			}
			// dd 계산
			if (r + 2 < n) {
				max_val[r + 2][c] = max(max_val[r + 2][c], eval(max_val[r][c], world[r + 1][c], world[r + 2][c] - '0'));
				min_val[r + 2][c] = min(min_val[r + 2][c], eval(min_val[r][c], world[r + 1][c], world[r + 2][c] - '0'));
			}
		}
	}

	cout << max_val[n - 1][n - 1] << ' ' << min_val[n - 1][n - 1] << '\n';
}