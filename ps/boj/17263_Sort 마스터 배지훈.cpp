#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 17263�� Sort ������ ������
// �з�: ���� ū ���� ã��
// ����:
//		���� �Է¹޾Ƽ� ���� ū ���Ҹ� ����ϴ� ����
// Ǯ��:
//		�Է� �����鼭 �ִ��� �����ϰ� ����Ѵ�.
priority_queue<int> pq;

int main() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (ans < a)
			ans = a;
	}
	printf("%d\n", ans);
}
