#include <iostream>
#include <cmath>

using namespace std;

// 17283�� I am Groot
// �з�: ����
// ����:
//		���� ������ �ٸ鼭 5 ���ϰ� �� �� ���� 2�辿 ���� ���� ���ϴ� ����
// Ǯ��:
//		�Ҽ��� �����ؼ� �����̹Ƿ� ���⿡ �����ؼ� Ǭ��.
int main() {
	double l, r;
	cin >> l >> r;
	int ans = 0;
	int branch = 2;
	while (1) {
		l *= (r / 100);
		l = floor(l);
		if (l <= 5.0)
			break;
		ans += branch * int(l);
		branch *= 2;
	}

	cout << ans << '\n';
}