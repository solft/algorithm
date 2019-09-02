#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1018번 체스판 다시 칠하기
// 분류: 브루트포스
// 문제:
//		주어진 체스판에서 8x8 영역을 뽑아내어
//		가장 적게 반전시켜 완성된 체스판 만드는 반전 수를 구하는 문제
// 풀이:
//		8x8칸짜리로 쪼개서 몇 번의 반전이 필요한지 다 구해준다.
int n, m;
char chess[55][55];

int sol(int l, int r) {
	int sum = l + r;
	int w = 0;
	int b = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((sum + i + j) % 2 == 0) {
				if (chess[l + i][r + j] == 'W')
					b++;
				else if (chess[l + i][r + j] == 'B')
					w++;
			}
			else {
				if (chess[l + i][r + j] == 'W')
					w++;
				else if (chess[l + i][r + j] == 'B')
					b++;
			}
		}
	}

	if (w < b)
		return w;
	else
		return b;
}

int main() {

	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> chess[i][j];


	int ans = 1000000000;

	for (int i = 0; i + 7 < n; i++) {
		for (int j = 0; j + 7 < m; j++) {
			int temp = sol(i, j);
			ans = min(ans, temp);
		}
	}
	cout << ans << '\n';
}