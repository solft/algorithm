#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <stack>
#define MAX_LEN 1000001 // �ִ� �Ÿ�
using namespace std;

// ���� ��, ���� ��, ���� ��
int n, m, q;

// ���� ����
int order[1000000];							// order[number] = i��° ����
vector<tuple<int, string, int>> location;   // tuple<number, name, flooding>

// �׷���
vector<vector<pair<int, int>>> graph; // graph[i] = i�� ������ ����� <�Ÿ�, ����> ����Ʈ

// �� ����
vector<int> dist;	// dist[i] = i�� �������� �ִ� �Ÿ�
vector<int> before; // before[i] = i�� ���� ������ ��� ����
vector<int> tree;	// tree[i] = i�� ���� �Ÿ� ������ �� tree size

// ���� ���� departure���� ���ͽ�Ʈ�� �˰��� ����
void dijkstra(int departure) {
	dist.assign(n, MAX_LEN);
	before.assign(n, -1);
	tree.assign(n, 0);

	priority_queue<pair<int, int>> pq;	// ���縦 ������ ���� ���� ����. < -�ѰŸ�, -������ȣ > �켱������ �ѰŸ��� �۰� ������ȣ�� ���� ���̴�.
	pq.push({ 0, -get<0>(location[departure]) });
	dist[departure] = 0;
	before[departure] = departure;
	int tree_size = 0;
	while (!pq.empty()) {
		int nowOrder = order[-pq.top().second];
		int nowCost = -pq.top().first;
		pq.pop();

		if (nowCost > dist[nowOrder]) continue;		 // �̹� �ִܰŸ��� ������ ����̹Ƿ� �ǳʶڴ�.
		tree[nowOrder] = ++tree_size;
		for (auto next : graph[nowOrder]) {
			int nextOrder = next.second;
			int nextCost = next.first;

			if (get<2>(location[nextOrder]) == 1)		// ���� ������ ħ���� ��� �ǳʶڴ�.
				continue;

			if (dist[nextOrder] > dist[nowOrder] + nextCost) { // ���� ������ ���ļ� ���� �������� ���� �Ÿ��� �� �۴ٸ� �ִ� �Ÿ��� ��θ� ���Ž����ش�.
				dist[nextOrder] = dist[nowOrder] + nextCost;
				before[nextOrder] = nowOrder;				// ��θ� ���� ���� ���� ����
				pq.push({ -dist[nextOrder], -get<0>(location[nextOrder]) }); // ������Ʈ�� ���� �������� ���簡 �ʿ��ϹǷ� priority_queue�� �־��ش�.
			}
		}
	}
}

// departure���� destination������ �ִ� ��θ� ����ϴ� �Լ�
void display_path(int departure, int destination) {
	cout << tree[destination] << ' '; // �켱 tree size�� ����Ѵ�.
	stack<int> path; // �Ųٷ� �����ϹǷ� stack�� ��� ������ �ִ´�.
	int pos = destination;
	path.push(pos);
	while (pos != departure) { // ������� ������ ���� ��� �����Ѵ�.
		pos = before[pos];
		path.push(pos);
	}
	while (!path.empty()) { // stack�� ������ ������ ������ ����Ѵ�.
		cout << get<0>(location[path.top()]) << ' ';
		path.pop();
	}
	cout << '\n';
}

int main() {
	// ����, ����, ���� ���� �Է� �κ�
	cin >> n >> m >> q;

	// ���� ���� Ȯ��
	location.resize(n);
	graph.resize(n);
	dist.resize(n);
	before.resize(n);
	tree.resize(n);

	// ���� ���� �Է�
	for (int i = 0; i < n; i++) {
		int number, flooding;
		string name;
		cin >> number >> name >> flooding;
		location[i] = make_tuple(number, name, flooding);
		order[number] = i;
	}

	// ���� ���� �Է�
	for (int i = 0; i < m; i++) {
		int loc1, loc2, weight;
		cin >> loc1 >> loc2 >> weight;
		graph[order[loc1]].push_back({ weight, order[loc2] });
		graph[order[loc2]].push_back({ weight, order[loc1] });
	}

	// ����
	for (int i = 0; i < q; i++) {
		char AB;
		int start, destination;
		cin >> AB >> start >> destination;

		if (AB == 'A') { // tree vertex size, start -> destination �ִ� �Ÿ�, start name, destination name / None
			if (get<2>(location[order[start]]) || get<2>(location[order[destination]])) { // ������̳� �������� ħ���Ǿ����� None�� ����Ѵ�.
				cout << "None\n";
				continue;
			}
			dijkstra(order[start]); // ��������� ���ͽ�Ʈ�� �˰��� ����
			if (dist[order[destination]] > 1000000) // �Ÿ��� 1000000 �̻��̸� None�� ����Ѵ�.
				cout << "None\n";
			else // tree vertex size, �ִ� �Ÿ�, ����� �̸�, ������ �̸��� ����Ѵ�.
				cout << tree[order[destination]] << " " << dist[order[destination]] << " " << get<1>(location[order[start]]) << " " << get<1>(location[order[destination]]) << "\n";
		}
		else if (AB == 'B') { // tree vertex size, path... / None
			if (get<2>(location[order[start]]) || get<2>(location[order[destination]])) { // ������̳� �������� ħ���Ǿ����� None�� ����Ѵ�.
				cout << "None\n";
				continue;
			}
			dijkstra(order[start]); // ��������� ���ͽ�Ʈ�� �˰��� ����
			if (dist[order[destination]] > 1000000) // �Ÿ��� 1000000 �̻��̸� None�� ����Ѵ�.
				cout << "None\n";
			else // tree vertex size, �ִ� ��θ� ����Ѵ�.
				display_path(order[start], order[destination]);
		}
	}
}