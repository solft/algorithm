#include <iostream>
using namespace std;

// 9663번 N-Queen
// 분류: 백트래킹
// 문제:
//		N*N 체스판에 N개의 퀸 말을 서로 공격 못하게 놓는 경우의 수 구하기
// 풀이:
//		백트래킹의 가장 기본 문제이다.
//		계속 못풀다가 다시 PS 공부를 시작하면서 깨우치게 되었다.
//		diag1은 / 대각 성분, diag2는 \ 대각 성분을 의미한다.
int n;
long long ans = 0;

int col[16];
int diag1[40];
int diag2[40];

void queen(int y) {
	if (y == n) { // 모든 행 검사를 마침
		ans++;
		return;
	}
	for (int x = 0; x < n; x++) {
		if (col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
		queen(y + 1);
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
	}
}

int main() {
	cin >> n;
	queen(0);
	cout << ans << '\n';
}