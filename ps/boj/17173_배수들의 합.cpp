#include <iostream>
#include <stack>
using namespace std;

// 17173�� ������� ��
// �з�: ����
// ����:
//		n������ ���ڵ� �� m���� ���� ������� �� ���� ���� ���ϴ� ����
// Ǯ��:
//		1000���� �����̹Ƿ� ����� �۾Ƽ�
//		�迭�� �ִ� �͵� üũ�� �ΰ� �� ���ߴ�.
//		��� ���� �����ϸ� �޺κ� ��� ���Ұ� üũ�ص� �Ǵµ� �������.
int num[1001];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int c;
		cin >> c;
		for (int j = 1; j * c <= n; j++)
			num[j * c] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (num[i] == 1)
			ans += i;
	}

	cout << ans << '\n';
}