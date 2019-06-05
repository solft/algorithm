#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 1325�� ȿ������ ��ŷ
// �з�: DFS, BFS
// ����:
//		����׷����� �־������� ���� ���� ������ ���� ������ ������ ã��
// Ǯ��:
//		�� ������ ���� DFS�� �����ؼ� ���� ������ ���� �������� ������������ ����Ѵ�.
//		DP�� �ð��� �����ų ���� ���� �� ����.
int n, m;
vector<vector<int>> computer;

int hacking = 0;
vector<int> visit;
void dfs(int c) {
	if (visit[c])
		return;
	visit[c] = 1;
	hacking++;
	for (auto next : computer[c]) {
		if (!visit[next])
			dfs(next);
	}
}

int main() {
	cin >> n >> m;
	computer.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; // b���� a�� ���� ��ΰ� �ִ�.
		cin >> a >> b;
		computer[b].push_back(a);
	}

	vector<int> ans;
	int max_computer = 0;
	for (int i = 1; i <= n; i++) {
		visit.assign(n + 1, 0);
		hacking = 0;
		dfs(i);
		ans.push_back(hacking);
		if (max_computer < hacking)
			max_computer = hacking;
	}

	for (int i = 0; i < n; i++)
		if (ans[i] == max_computer)
			cout << i + 1 << " ";
	cout << '\n';
}
