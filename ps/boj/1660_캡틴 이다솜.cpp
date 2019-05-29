#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 2000000000

// 1660�� ĸƾ �̴ټ�
// �з�: DP
// ����:
//		������[i] = ������[i-1] + (i*(i+1))/2 �� ��Ģ���� ���� ��
//		n���� ������ ������ ��� ���� �� ���� �ּ� ��� ������ ã�� ����
// Ǯ��:
//		������ ������ ���� ����ġ�� �����ϰ� ���� DPó�� Ǯ�� �ȴ�.
vector<int> canon;
vector<int> dp;

int oneToN(int n) {
	return n * (n + 1) / 2;
}

int main() {
	canon.resize(122);
	

	int n;
	cin >> n;
	dp.resize(n + 1, MAX);
	dp[0] = 0;

	canon[1] = 1;
	for (int i = 2; i <= 121; i++) {
		canon[i] = canon[i - 1] + oneToN(i);
	}
	
	for (int i = 0; i <= n; i++) {
		for (auto k : canon) {
			if (i - k >= 0)
				dp[i] = min(dp[i], dp[i - k] + 1);
			else
				break;
		}
	}

	cout << dp[n] << '\n';
}