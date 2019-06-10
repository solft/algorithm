#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 17269�� �̸����� �׽�Ʈ
// �з�: ���ڿ� ������ ó���ϱ�
// ����:
//		�� ���ڿ��� �Է� �ް� �����ư��� � �������� Ȯ�� ��
//		���� ȹ�� ���� ��� ����� ������ ������ ���� 2���� ����ϴ� ����
// Ǯ��:
//		�� ���ڿ��� ���ļ� ���� ȹ�� �迭�� �����
//		�� ���ڸ� ���� ������ �����ش�.
int result[220];

int main() {
	int alpha[26] = { 3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1 };
	int n, m;
	string a, b;
	cin >> n >> m;
	cin >> a >> b;


	int idx_a = 0;
	int idx_b = 0;
	for (int i = 0; i < m + n; i++) {
		if (idx_a >= n) {
			result[i] = alpha[b[idx_b] - 'A'];
			idx_b++;
		}
		else if (idx_b >= m) {
			result[i] = alpha[a[idx_a] - 'A'];
			idx_a++;
		}
		else {
			if (i % 2 == 0) {
				result[i] = alpha[a[idx_a] - 'A'];
				idx_a++;
			}
			else {
				result[i] = alpha[b[idx_b] - 'A'];
				idx_b++;
			}
		}
	}

	for (int i = m + n - 2; i > 0; i--)
		for (int j = 0; j <= i; j++)
			result[j] = (result[j] + result[j + 1]) % 10;

	cout << result[0] * 10 + result[1] << "%\n";
}
