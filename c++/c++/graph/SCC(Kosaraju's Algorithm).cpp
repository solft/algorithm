#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

// SCC ã��
// �ڻ���� �˰���
// DFS�� �� �ϰ� ������ ���������� ���ÿ� ���� �ڿ�
// ���ÿ��� �ϳ��� ������ ������ �׷����� DFS�ϸ� ������ ������ SCC�� ���´�.
vector<bool> visited;
vector<vector<int>> graph;
vector<vector<int>> regraph;
stack<int> dfs_end_stack;

vector<vector<int>> scc;
int scc_size = 0;

void dfs(int v) {
	visited[v] = true;
	for (int next : graph[v]) {
		if (visited[next])
			continue;
		dfs(next);
	}
	dfs_end_stack.push(v);
}

void kosaraju(int v, int c) {
	visited[v] = true;
	scc[c].push_back(v);
	for (int next : regraph[v]) {
		if (visited[next])
			continue;
		kosaraju(next, c);
	}
}

int main() {
	int v, e;
	cin >> v >> e;

	visited.resize(v + 1);
	graph.resize(v + 1);
	regraph.resize(v + 1);

	// �׷��� �����
	// ���� ��ȣ 1 ~ e
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		regraph[b].push_back(a);
	}

	// ù DFS
	// stack �����
	for (int i = 1; i <= v; i++) {
		if (visited[i])
			continue;
		dfs(i);
	}

	// ������ �׷������� DFS
	visited.assign(v + 1, false);
	while (!dfs_end_stack.empty()) {
		int now = dfs_end_stack.top();
		dfs_end_stack.pop();
		if (visited[now])
			continue;
		scc.resize(++scc_size);
		kosaraju(now, scc_size - 1);
	}

	// ��� ���
	for (auto s : scc) {
		for (auto v : s)
			cout << v << ' ';
		cout << '\n';
	}
}