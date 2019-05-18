#include <iostream>
using namespace std;

// 9663�� N-Queen
// �з�: ��Ʈ��ŷ
// ����:
//		N*N ü���ǿ� N���� �� ���� ���� ���� ���ϰ� ���� ����� �� ���ϱ�
// Ǯ��:
//		��Ʈ��ŷ�� ���� �⺻ �����̴�.
//		��� ��Ǯ�ٰ� �ٽ� PS ���θ� �����ϸ鼭 ����ġ�� �Ǿ���.
//		diag1�� / �밢 ����, diag2�� \ �밢 ������ �ǹ��Ѵ�.
int n;
long long ans = 0;

int col[16];
int diag1[40];
int diag2[40];

void queen(int y) {
	if (y == n) { // ��� �� �˻縦 ��ħ
		ans++;
		return;
	}
	for (int x = 0; x < n; x++) {
		if (col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
		queen(y + 1);
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
	}
}

int main() {
	cin >> n;
	queen(0);
	cout << ans << '\n';
}