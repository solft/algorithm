#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define V_SIZE 10000

vector<vector<int>> vt;

// dfs ����� Topological sort
stack<int> st;
int visited[V_SIZE];

// indegree�� ����� Topological sort
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
	/* dfs�� ����� Topological Sort
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
		if (!in[i]) // i�� ������ indegree�� 0�̸�
			pq.push(-i); // pq�� ������ �ִ´�
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