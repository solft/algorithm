#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <stack>
#define MAX_LEN 1000001 // 최대 거리
using namespace std;

// 지역 수, 도로 수, 질의 수
int n, m, q;

// 지역 정보
int order[1000000];							// order[number] = i번째 정점
vector<tuple<int, string, int>> location;   // tuple<number, name, flooding>

// 그래프
vector<vector<pair<int, int>>> graph; // graph[i] = i번 정점에 연결된 <거리, 정점> 리스트

// 답 관련
vector<int> dist;	// dist[i] = i번 정점까지 최단 거리
vector<int> before; // before[i] = i번 정점 이전에 밟는 정점
vector<int> tree;	// tree[i] = i번 정점 거리 정해질 때 tree size

// 정점 순서 departure에서 다익스트라 알고리즘 시작
void dijkstra(int departure) {
	dist.assign(n, MAX_LEN);
	before.assign(n, -1);
	tree.assign(n, 0);

	priority_queue<pair<int, int>> pq;	// 조사를 시작할 곳의 정보 저장. < -총거리, -지역번호 > 우선순위는 총거리가 작고 지역번호가 작은 순이다.
	pq.push({ 0, -get<0>(location[departure]) });
	dist[departure] = 0;
	before[departure] = departure;
	int tree_size = 0;
	while (!pq.empty()) {
		int nowOrder = order[-pq.top().second];
		int nowCost = -pq.top().first;
		pq.pop();

		if (nowCost > dist[nowOrder]) continue;		 // 이미 최단거리가 구해진 경우이므로 건너뛴다.
		tree[nowOrder] = ++tree_size;
		for (auto next : graph[nowOrder]) {
			int nextOrder = next.second;
			int nextCost = next.first;

			if (get<2>(location[nextOrder]) == 1)		// 다음 지역이 침수일 경우 건너뛴다.
				continue;

			if (dist[nextOrder] > dist[nowOrder] + nextCost) { // 현재 정점을 거쳐서 다음 정점까지 가는 거리가 더 작다면 최단 거리와 경로를 갱신시켜준다.
				dist[nextOrder] = dist[nowOrder] + nextCost;
				before[nextOrder] = nowOrder;				// 경로를 위해 이전 정점 저장
				pq.push({ -dist[nextOrder], -get<0>(location[nextOrder]) }); // 업데이트된 곳의 정점에서 조사가 필요하므로 priority_queue에 넣어준다.
			}
		}
	}
}

// departure에서 destination까지의 최단 경로를 출력하는 함수
void display_path(int departure, int destination) {
	cout << tree[destination] << ' '; // 우선 tree size를 출력한다.
	stack<int> path; // 거꾸로 진행하므로 stack에 경로 정보를 넣는다.
	int pos = destination;
	path.push(pos);
	while (pos != departure) { // 출발점을 만날때 까지 계속 진행한다.
		pos = before[pos];
		path.push(pos);
	}
	while (!path.empty()) { // stack의 정보를 밖으로 빼내며 출력한다.
		cout << get<0>(location[path.top()]) << ' ';
		path.pop();
	}
	cout << '\n';
}

int main() {
	// 지역, 도시, 질의 개수 입력 부분
	cin >> n >> m >> q;

	// 저장 공간 확보
	location.resize(n);
	graph.resize(n);
	dist.resize(n);
	before.resize(n);
	tree.resize(n);

	// 지역 정보 입력
	for (int i = 0; i < n; i++) {
		int number, flooding;
		string name;
		cin >> number >> name >> flooding;
		location[i] = make_tuple(number, name, flooding);
		order[number] = i;
	}

	// 도로 정보 입력
	for (int i = 0; i < m; i++) {
		int loc1, loc2, weight;
		cin >> loc1 >> loc2 >> weight;
		graph[order[loc1]].push_back({ weight, order[loc2] });
		graph[order[loc2]].push_back({ weight, order[loc1] });
	}

	// 질의
	for (int i = 0; i < q; i++) {
		char AB;
		int start, destination;
		cin >> AB >> start >> destination;

		if (AB == 'A') { // tree vertex size, start -> destination 최단 거리, start name, destination name / None
			if (get<2>(location[order[start]]) || get<2>(location[order[destination]])) { // 출발점이나 도착점이 침수되었으면 None을 출력한다.
				cout << "None\n";
				continue;
			}
			dijkstra(order[start]); // 출발점에서 다익스트라 알고리즘 진행
			if (dist[order[destination]] > 1000000) // 거리가 1000000 이상이면 None을 출력한다.
				cout << "None\n";
			else // tree vertex size, 최단 거리, 출발점 이름, 도착점 이름을 출력한다.
				cout << tree[order[destination]] << " " << dist[order[destination]] << " " << get<1>(location[order[start]]) << " " << get<1>(location[order[destination]]) << "\n";
		}
		else if (AB == 'B') { // tree vertex size, path... / None
			if (get<2>(location[order[start]]) || get<2>(location[order[destination]])) { // 출발점이나 도착점이 침수되었으면 None을 출력한다.
				cout << "None\n";
				continue;
			}
			dijkstra(order[start]); // 출발점에서 다익스트라 알고리즘 진행
			if (dist[order[destination]] > 1000000) // 거리가 1000000 이상이면 None을 출력한다.
				cout << "None\n";
			else // tree vertex size, 최단 경로를 출력한다.
				display_path(order[start], order[destination]);
		}
	}
}