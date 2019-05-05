#include <iostream>
#include <algorithm>
#include <queue>
using namespace std; 
// 1987번 알파벳
// 분류: DFS
// 문제:
//		2차원 행렬 (0,0)에서 시작하여 칸의 알파벳이
//		중복되지 않게 최대 몇 칸 이동 가능한지 구하는 문제
// 풀이:
//		칸에 도착할 때마다 해당 알파벳을 사용 표시하고
//		사용한 알파벳 증가시킨뒤
//		다음 탐색점은 이동 가능하고 사용하지 않은 알파벳일 때만 dfs를 진행한다.
//		dfs가 끝나면 사용한 알파벳을 해제 시켜준다.
int n, m;
char board[20][20];
int alphabet[26] = { 0, };
int maxAlphabet = 0;
int useAlphabet = 0;

int mr[4] = { -1, 0, 1, 0 };
int mc[4] = { 0, 1, 0, -1 };

void dfs(int r, int c) {

	alphabet[board[r][c] - 'A'] = 1;
	useAlphabet++;
	if (maxAlphabet < useAlphabet)
		maxAlphabet = useAlphabet;

	for (int i = 0; i < 4; i++) {
		if (r + mr[i] >= 0 && r + mr[i] < n && c + mc[i] >= 0 && c + mc[i] < m) {
			if (alphabet[board[r + mr[i]][c + mc[i]]-'A'] == 0) {
				dfs(r + mr[i], c + mc[i]);
			}
		}
	}

	alphabet[board[r][c] - 'A'] = 0;
	useAlphabet--;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
	dfs(0, 0);
	cout << maxAlphabet << endl;
}