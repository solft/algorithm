#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 11651 ��ǥ �����ϱ� 2
// �з�: ����
// ����:
//		��ǥ�� �־����� y�� �������� -> x�� ������������ ����
// Ǯ��:
//		sort() ����ߴ�. endl ����ϸ� �ð��ʰ� ���.
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