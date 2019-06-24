#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 2502�� �� �Դ� ȣ����
// �з�: ������
// ����:
//		�Ǻ���ġ[d] * a + �Ǻ���ġ[d+1] * b == k�� a�� b�� ���ϴ� ����
// Ǯ��:
//		�Ǻ���ġ ������ 30���� ���صΰ� a, b�� b ���� �������Ѻ��� ã�´�.
//		������ a�� ������Ű�� �ٽ� b�� �ٲ� ��� ã�ٰ� �����ϸ� ����Ѵ�.
int a[31];
int b[31];

int main() {
	a[1] = 1;
	a[2] = 0;
	a[3] = 1;
	b[1] = 0;
	b[2] = 1;
	b[3] = 1;

	for (int i = 4; i <= 30; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}
	
	int d, k;
	cin >> d >> k;

	for (int i = 1; a[d] * i <= k; i++) {
		for (int j = 1; a[d] * i + b[d] * j <= k; j++) {
			if (a[d] * i + b[d] * j == k) {
				cout << i << '\n' << j << '\n';
				return 0;
			}
		}
	}
}