#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// 13986�� Gravity
// �з�: ����
// ����:
//		����� �־����� 'o'�� '.'�ִ� ���� ����ĥ �� ���� ��
//		�߷��� �ִ� �� ó�� �ٴ����� �������� ���� ���´� ��� �Ǵ��� ����ϴ� ����
// Ǯ��:
//		�� �ϳ� ��� �Ʒ������� 'o'�� ������ ������ �� ���� �� ���� ��������.
//		�̷��� ��� ���� �ݺ��ϸ� �ȴ�.
char pic[55][55];

int main() {
	int x, y;
	cin >> y >> x;
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			cin >> pic[i][j];

	// �� ���� �ؿ��� ���� �ö󰣴�.
	for (int i = 0; i < x; i++) {
		for (int j = y - 1; j >= 0; j--) {
			if (pic[j][i] == 'o') {
				int drop = j;
				while (1) {
					if (drop + 1 < y && pic[drop + 1][i] == '.') {
						pic[drop][i] = '.';
						pic[drop + 1][i] = 'o';
						drop++;
					}
					else
						break;
				}
			}
		}
	}

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cout << pic[i][j];
		}
		cout << '\n';
	}
}