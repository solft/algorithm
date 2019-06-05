#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 1325번 효율적인 해킹
// 분류: DFS, BFS
// 문제:
//		유향그래프가 주어졌을때 가장 많은 정점에 도달 가능한 정점들 찾기
// 풀이:
//		각 정점에 대해 DFS를 수행해서 가장 개수가 많은 정점들을 오름차순으로 출력한다.
//		DP로 시간을 단축시킬 수도 있을 것 같다.
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
		int a, b; // b에서 a로 가는 경로가 있다.
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
