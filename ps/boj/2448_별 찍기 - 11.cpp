#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

// 2448�� �� ��� - 11
// �з�: ��Ģ ã��
// ����:
//		��Ģ�� �°� �� ���
// Ǯ��:
//		�� ���̽����� 3���� ���� ���̽��� ��������
//		�ּ� ���̽��� ũ�� 3¥���̹Ƿ�
//		ũ�� 3�� ���� �� ���� ��ͷ� �����ؼ� ��ü �׸��� ������״�.
char star[7000][7000];

void makeStar(int size, int y, int x) {
	if (size == 3) {
		star[y][x] = '*';

		star[y + 1][x - 1] = '*';
		star[y + 1][x] = ' ';
		star[y + 1][x + 1] = '*';

		star[y + 2][x - 2] = '*';
		star[y + 2][x - 1] = '*';
		star[y + 2][x] = '*';
		star[y + 2][x + 1] = '*';
		star[y + 2][x + 2] = '*';
	}
	else {
		makeStar(size / 2, y, x);
		makeStar(size / 2, y + size / 2, x - size / 2);
		makeStar(size / 2, y + size / 2, x + size / 2);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n * 2; j++)
			star[i][j] = ' ';
	makeStar(n, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n * 2; j++)
			cout << star[i][j];
		cout << '\n';
	}
}