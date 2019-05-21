#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define V_SIZE 10000

vector<vector<int>> vt;

// dfs 사용한 Topological sort
stack<int> st;
int visited[V_SIZE];

// indegree를 사용한 Topological sort
priority_queue<int> pq;
int in[V_SIZE];

int n, m, x, y;

void dfs(int v) {
	visited[v] = true;
	for (auto i : vt[v]) {
		if (visited[i])
			continue;
		dfs(i);
	}
	st.push(v);
}

int main() {
	/* dfs를 사용한 Topological Sort
	cin >> n >> m;
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		vt[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i])
			dfs(i);
	}
	while (st.size()) {
		cout<<(st.top())<<' ';
		st.pop();
	}
	cout << '\n';
	*/

	cin >> n >> m;
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		vt[x].push_back(y);
		in[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!in[i]) // i번 정점의 indegree가 0이면
			pq.push(-i); // pq에 음수로 넣는다
	}
	while (pq.size()) {
		int here = -pq.top();
		pq.pop();
		cout << here << ' ';
		for(int there:vt[here]){
			in[there]--;
			if (!in[there])
				pq.push(-there);
		}
	}
}