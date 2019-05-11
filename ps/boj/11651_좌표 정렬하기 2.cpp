#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 11651 좌표 정렬하기 2
// 분류: 정렬
// 문제:
//		좌표가 주어지면 y에 오름차순 -> x에 오름차순으로 정렬
// 풀이:
//		sort() 사용했다. endl 사용하면 시간초과 뜬다.
typedef pair<int, int> ii;
vector<ii> point;

int main() {
	int n;
	scanf("%d", &n);
	point.assign(n, ii(0, 0));
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		point[i] = ii(b, a);
	}

	sort(point.begin(), point.end());

	for (int i = 0; i < n; i++)
		printf("%d %d\n", point[i].second, point[i].first);
}