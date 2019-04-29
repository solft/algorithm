#include <iostream>
using namespace std; 
typedef long long ll;

// 16395�� �Ľ�Į�� �ﰢ��
// ����:
//		�Ľ�Į�� �ﰢ������ n���� k��° �� ���ϴ� ����
// Ǯ��:
//		(n-1)C(k-1) ���ϴ� ������.
//		�Է°��� �����Ƿ� ��Ϳ� DP�� �̿��� ���� ��� ���ϴ� ������� Ǯ����.
ll dp[40][40] = { 0, };

ll C(int x, int y) {
	if (y == 0 || x == y)
		return dp[x][y] = ll(1);
	else if (dp[x][y] != 0)
		return dp[x][y];
	else 
		return dp[x][y] = C(x - 1, y - 1) + C(x - 1, y);
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << C(n-1, k-1) << endl;
}