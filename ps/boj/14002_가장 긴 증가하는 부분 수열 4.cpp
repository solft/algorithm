#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

// 14002�� ���� �� �����ϴ� �κ� ���� 4
// �з�: LIS
// ����:
//		LIS�� ���ϰ� LIS�� ����Ʈ�� ����ϴ� ����
// Ǯ��:
//		ū ������� ���׸�Ʈ Ʈ���� �̿��ؾ��ϴµ� ����� �����Ƿ� dp �̿�
//		�� ��ġ�� LIS�� ������Ʈ �� �� ���� LIS list�� �߰��ϸ� ������Ʈ ���־���.
//		�׸��� �������� ���� LIS ���̿� �Ȱ��� LIS list�� ������־���.
int main() {
	vector<int> sequence;

	int n;
	int ans = 1;
	cin >> n;
	sequence.resize(n);
	for (int i = 0; i < n; i++)
		cin >> sequence[i];

	// O(N^2)�� ���ϱ�
	vector<int> dp;
	vector<vector<int>> lisList;
	dp.resize(n, 0);
	lisList.resize(n);
	for (int i = 0; i < n; i++) {
		if (dp[i] == 0) {
			lisList[i].push_back(sequence[i]);
			dp[i] = 1;
		}
		for (int j = 0; j < i; j++)
			if (sequence[i] > sequence[j])
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					if (ans < dp[i])
						ans = dp[i];
					lisList[i] = lisList[j];
					lisList[i].push_back(sequence[i]);
				}
	}

	cout << ans << '\n';
	for (int i = 0; i < n; i++) {
		if (lisList[i].size() == ans) {
			for (auto s : lisList[i])
				cout << s << ' ';
			cout << '\n';
			break;
		}
	}
}