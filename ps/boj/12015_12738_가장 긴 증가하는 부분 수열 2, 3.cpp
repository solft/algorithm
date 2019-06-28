#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

// 12015�� 12738�� ���� �� �����ϴ� �κ� ���� 2, 3
// �з�: LIS
// ����:
//		LIS�� ���ϴµ� ������ ��û ��� O(n log n)�� �ð� ���⵵�� Ǯ��ߵ�
// Ǯ��:
//		�� ���� �� ��ġ�� �������̳� lower_bound�ĸ� 
//		���� Ž������ ������ ���� LIS�� ������Ʈ�Ͽ� Ǭ��.
int n;
int num[1000001];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	vector<int> lis;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (lis.empty() || lis.back() < num[i]) {
			lis.push_back(num[i]);
			ans++;
		}
		else {
			auto insert_position = lower_bound(lis.begin(), lis.end(), num[i]);
			*insert_position = num[i];
		}
	}
	printf("%d\n", ans);
}