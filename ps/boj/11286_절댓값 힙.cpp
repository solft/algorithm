#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 11286�� ���� ��
// �з�: ��
// ����:
//		������ �۰� ������ ���ٸ� ���� ���� ���� ������ ���� ����� ����
// Ǯ��:
//		STL�� priority_queue�� �̿��ؼ� �״�� �����Ͽ���.
int main() {
	priority_queue<pair<int, int>> apq;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int d;
		scanf("%d", &d);
		if (d == 0) {
			if (apq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", apq.top().first * apq.top().second);
				apq.pop();
			}
		}
		else if (d > 0) {
			apq.push({ -d, -1 });
		}
		else if (d < 0) {
			apq.push({ d, 1 });
		}
	}
}