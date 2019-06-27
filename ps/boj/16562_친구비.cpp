#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

// 16562번 친구비
// 분류: Union Find
// 문제:
//		모든 덩어리를 하나로 만들기 위한 최소 비용 구하기
// 풀이:
//		union find로 합칠 때 합쳐진 덩어리를 가져올 수 있는 최소비용을 저장해 두고
//		마지막에 합칠때 해당 비용으로 전체를 합쳐서 제한된 비용 안으로
//		모든 덩어리를 합칠수 있는지 확인하고 가능하면 비용을 출력하면 된다.
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