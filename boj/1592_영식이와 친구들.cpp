#include <iostream>
using namespace std;

// 1592�� �����̿� ģ����
// Ǯ��:
//		���ǿ� ���� �ڷ� ������ ������ ������
//		������ó�� ����ϸ� �ȴ�.
//		�ݺ��� ������
//		1. ���� �޴´� (F[ball] 1����)
//		2. ���� �˻�(m�� �̻� �޾Ҵ���?)
//		3. ������
//		4. ���� ���� ��� ���ϱ�
int main() {
	int n, m, l;
	cin >> n >> m >> l;

	int F[1001] = { 0, };

	int ball = 0;
	int ans = 0;
	while (true) {
		F[ball]++;
		if (F[ball] >= m)
			break;
		ans++;

		if (F[ball] % 2 == 1) {	
			ball += l;
			ball %= n;
		}
		else {
			ball += n;
			ball -= l;
			ball %= n;
		}
	}
	cout << ans << endl;
}