#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 2991�� �糪�� ��
// �з�: ����
// ����:
//		���� �糪�� ���� �־����� 
//		�ش� �ð��� ����� �糪���� ���
// Ǯ��:
//		�ִ�ð��� 999�̹Ƿ� ���� �糪�� ���� �ð��� 1�� �����־���.
int dog[1000];

int main() {
	int a, b, c, d;
	int p, m, n;
	cin >> a >> b >> c >> d;
	cin >> p >> m >> n;

	int index = 1;
	while (true) {
		for (int i = 0; i < a; i++)
			dog[index++]++;
		for (int i = 0; i < b; i++)
			index++;
		if (index > 1000)
			break;
	}
	index = 1;
	while (true) {
		for (int i = 0; i < c; i++)
			dog[index++]++;
		for (int i = 0; i < d; i++)
			index++;
		if (index > 1000)
			break;
	}

	cout << dog[p] << '\n';
	cout << dog[m] << '\n';
	cout << dog[n] << '\n';
}
