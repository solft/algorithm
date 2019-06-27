#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

// 16562�� ģ����
// �з�: Union Find
// ����:
//		��� ����� �ϳ��� ����� ���� �ּ� ��� ���ϱ�
// Ǯ��:
//		union find�� ��ĥ �� ������ ����� ������ �� �ִ� �ּҺ���� ������ �ΰ�
//		�������� ��ĥ�� �ش� ������� ��ü�� ���ļ� ���ѵ� ��� ������
//		��� ����� ��ĥ�� �ִ��� Ȯ���ϰ� �����ϸ� ����� ����ϸ� �ȴ�.
#define NODE_SIZE 10001
int parent[NODE_SIZE];
int ranking[NODE_SIZE] = { 0, };
int n, m, k;
int money[NODE_SIZE];
bool friends[NODE_SIZE];
int v, w;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	if (ranking[x] < ranking[y]) { 
		parent[x] = y; 
		money[y] = min(money[y], money[x]);
	}
	else {
		parent[y] = x;
		money[x] = min(money[y], money[x]);
	}
	if (ranking[x] == ranking[y]) ranking[x]++;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> money[i];
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	int total = 0;
	for (int i = 1; i <= n; i++) {
		int friendParent = Find(i);
		if (!friends[friendParent]) {
			friends[friendParent] = true;
			total += money[friendParent];
		}

		if (total > k)
			break;
	}

	if (total > k)
		cout << "Oh no\n";
	else
		cout << total << "\n";
}