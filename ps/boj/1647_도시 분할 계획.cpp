#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 1647�� ���� ���� ��ȹ
// �з�: MST, ũ�罺Į �˰���, ���Ͽ� ���ε�
// ����:
//		MST�� ���ϴµ� �� ����� ���� �� ����� �ϹǷ� �� ������ ������ �߰����� �ʴ´�.
// Ǯ��:
//		ũ�罺Į �˰������� MST�� ���� �����ٰ� ������ ������ ������ �ʴ´�.
#define NODE_SIZE 100001
int parant[NODE_SIZE];
int ranking[NODE_SIZE] = { 0, };

int Find(int x) {
	if (parant[x] == x) return x;
	return parant[x] = Find(parant[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	if (ranking[x] < ranking[y]) parant[x] = y;
	else parant[y] = x;
	if (ranking[x] == ranking[y]) ranking[x]++;
}

int n, m;
vector<pair<int, pair<int, int>>> edgeList;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parant[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edgeList.push_back({ w, {a, b} });
	}

	sort(edgeList.begin(), edgeList.end());
	int ans = 0;
	int count = 1;
	for (auto k : edgeList) {
		
		int weight = k.first;
		int left = k.second.first;
		int right = k.second.second;

		// ���� �׷�
		if (Find(left) == Find(right)) {
			continue;
		}
		else {
			ans += weight;
			count++;
			Union(left, right);
		}
		if (count >= n - 1)
			break;
	}
	cout << ans << '\n';
}