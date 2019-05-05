#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

// 1707�� �̺� �׷���
// �з�: �׷���, bipartite graph, DFS or BFS
// ����:
//		����� �������� �־����� �̰� �̺� �׷������� Ȯ���ϴ� ����
// Ǯ��:
//		color�� ������ �迭�� ������ְ�
//		DFS ����� �������� ���� ������� �������� �־��ش�.
//		���� �湮�� ���� ���� ���� ���� ���ٸ� �̺� �׷����� �ƴϴ�.
vector<int> adjList[20001];
bool visit[20001] = {};
bool color[20001] = {};
bool isTwoColorable = true;

void dfs(int v) {
	visit[v] = true;
	for (auto w : adjList[v])
		if (!visit[w]) {
			color[w] = !color[v];
			dfs(w);
		}
		else if (color[w] == color[v]) {
			isTwoColorable = false;
		}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e;
		int one, another;
		for (int i = 0; i < e; i++) {
			cin >> one >> another;
			adjList[one].push_back(another);
			adjList[another].push_back(one);
		}

		
		isTwoColorable = true;

		for (int i = 1; i <= v; i++) {
			dfs(i);
			for (int j = 1; j <= v; j++) {
				visit[i] = false;
				color[i] = false;
			}
			if (!isTwoColorable)
				break;
		}
			

		if (isTwoColorable)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;


		for (int i = 1; i <= v; i++) {
			adjList[i].clear();
			visit[i] = false;
			color[i] = false;
		}	
	}
}