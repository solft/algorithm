#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

// SCC 찾기
// 코사라주 알고리즘
// DFS한 번 하고 끝나는 정점순으로 스택에 넣은 뒤에
// 스택에서 하나씩 빼내며 역방향 그래프에 DFS하며 도달한 정점을 SCC로 묶는다.
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

	// 그래프 만들기
	// 정점 번호 1 ~ e
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		regraph[b].push_back(a);
	}

	// 첫 DFS
	// stack 만들기
	for (int i = 1; i <= v; i++) {
		if (visited[i])
			continue;
		dfs(i);
	}

	// 역방향 그래프에서 DFS
	visited.assign(v + 1, false);
	while (!dfs_end_stack.empty()) {
		int now = dfs_end_stack.top();
		dfs_end_stack.pop();
		if (visited[now])
			continue;
		scc.resize(++scc_size);
		kosaraju(now, scc_size - 1);
	}

	// 결과 출력
	for (auto s : scc) {
		for (auto v : s)
			cout << v << ' ';
		cout << '\n';
	}
}