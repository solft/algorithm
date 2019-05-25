#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

// 2447�� �� ��� - 10
// �з�: ��Ģ ã��, Divide and Conquer
// ����:
//		��Ģ�� �°� �� ���
// Ǯ��:
//		�� ���̽����� 9�������� ����� �����°� ���Ƽ� 
//		9�� �Լ� ȣ���ϴ� ��ͷ� Ǯ����.
char star[6561][6561];

void makeStar(int size, int state, int y, int x) {
	if (size == 1) {
		if (state == 1)
			star[y][x] = '*';
		else if (state == 2)
			star[y][x] = ' ';
	}
	else {
		if (state == 1) {
			makeStar(size / 3, 1, y, x);
			makeStar(size / 3, 1, y, x + size / 3);
			makeStar(size / 3, 1, y, x + (size / 3) * 2);

			makeStar(size / 3, 1, y + size / 3, x);
			makeStar(size / 3, 2, y + size / 3, x + size / 3);
			makeStar(size / 3, 1, y + size / 3, x + (size / 3) * 2);

			makeStar(size / 3, 1, y + (size / 3) * 2, x);
			makeStar(size / 3, 1, y + (size / 3) * 2, x + size / 3);
			makeStar(size / 3, 1, y + (size / 3) * 2, x + (size / 3) * 2);
		}
		else if (state == 2) {
			makeStar(size / 3, 2, y, x);
			makeStar(size / 3, 2, y, x + size / 3);
			makeStar(size / 3, 2, y, x + size / 3 * 2);

			makeStar(size / 3, 2, y + size / 3, x);
			makeStar(size / 3, 2, y + size / 3, x + size / 3);
			makeStar(size / 3, 2, y + size / 3, x + (size / 3) * 2);

			makeStar(size / 3, 2, y + (size / 3) * 2, x);
			makeStar(size / 3, 2, y + (size / 3) * 2, x + size / 3);
			makeStar(size / 3, 2, y + (size / 3) * 2, x + (size / 3) * 2);
		}
	}
}

int main() {
	int n;
	cin >> n;
	makeStar(n, 1, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << star[i][j];
		cout << '\n';
	}
}