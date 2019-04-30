#include <iostream>
using namespace std; 
// 1236번 성지키기
// 문제:
//		row와 col에 적어도 한명의 경비원이 있어야되는데
//		주어진 상태에서 조건을 만족하려면 몇 명이 추가되어야 하는지 구하는 문제
// 풀이:
//		각 row와 col에 몇 명인지 확인하고
//		우선 row와 col 모두 0인 위치에 추가한 뒤
//		row가 0인 곳, col이 0인 곳에 추가시켜
//		조건을 만족시키고 그 때 추가한 인원을 세면 된다.
char castle[51][51];
int row[51] = { 0, };
int col[51] = { 0, };

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> castle[i][j];

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (castle[i][j] == 'X')
				row[i]++, col[j]++;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (row[i] == 0 && col[j] == 0)
				ans++, row[i]++, col[j]++;

	for (int i = 0; i < n; i++)
		if (row[i] == 0)
			ans++, row[i]++;

	for (int j = 0; j < m; j++)
		if (col[j] == 0)
			ans++, col[j]++;
	cout << ans << endl;
}