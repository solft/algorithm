#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

// 1707번 이분 그래프
// 분류: 그래프, bipartite graph, DFS or BFS
// 문제:
//		연결된 정점들이 주어지고 이게 이분 그래프인지 확인하는 문제
// 풀이:
//		color를 지정할 배열을 만들어주고
//		DFS 진행시 다음번의 색은 현재색의 반전으로 넣어준다.
//		만약 방문할 곳의 색이 현재 색과 같다면 이분 그래프가 아니다.
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