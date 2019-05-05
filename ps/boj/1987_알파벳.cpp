#include <iostream>
#include <algorithm>
#include <queue>
using namespace std; 
// 1987�� ���ĺ�
// �з�: DFS
// ����:
//		2���� ��� (0,0)���� �����Ͽ� ĭ�� ���ĺ���
//		�ߺ����� �ʰ� �ִ� �� ĭ �̵� �������� ���ϴ� ����
// Ǯ��:
//		ĭ�� ������ ������ �ش� ���ĺ��� ��� ǥ���ϰ�
//		����� ���ĺ� ������Ų��
//		���� Ž������ �̵� �����ϰ� ������� ���� ���ĺ��� ���� dfs�� �����Ѵ�.
//		dfs�� ������ ����� ���ĺ��� ���� �����ش�.
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