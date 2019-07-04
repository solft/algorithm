#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// 13565번 침투
// 분류: DFS
// 문제:
//		위쪽의 0인 곳에서 출발해서 아래쪽 0인 곳에 도달할 수 있는지 확인하는 문제
// 풀이:
//		1행의 0인 곳에서 DFS 해주고 나서 n-1 행에서 바뀐 곳이 있는지 확인하면 된다.
char percolate[1001][1001];
int visit[1001][1001];
int n, m;
int mr[4] = { -1, 0, 1, 0 };
int mc[4] = { 0, 1, 0, -1 };

void dfs(int r, int c) {
	percolate[r][c] = '2';

	for (int i = 0; i < 4; i++)
		if (r + mr[i] >= 0 && r + mr[i] < n && c + mc[i] >= 0 && c + mc[i] < m)
			if (percolate[r + mr[i]][c + mc[i]] == '0')
				dfs(r + mr[i], c + mc[i]);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> percolate[i][j];

	for (int i = 0; i < m; i++)
		if (percolate[0][i] == '0')
			dfs(0, i);

	bool ans = false;
	for (int i = 0; i < m; i++)
		if (percolate[n - 1][i] == '2') {
			ans = true;
			break;
		}

	if (ans)
		cout << "YES\n";
	else
		cout << "NO\n";
}