#include <iostream>
using namespace std;

// 11383�� ��
// ����:
//		�� ���� �迭�� �Է¹ް� ù ���� �迭�� ���� �������� 
//		2���ϸ� �� ��° ���� �迭�� ������ ���ϴ� ���� ���� ����
// Ǯ��:
//		2���� ���� �迭�� �Է� �ް� ���� �� ���ؼ� Ǯ����.
//		�迭 ����� �۾� �׳� �����ص� �ƹ� ���� ���� ���δ�.
//		go�� Ǯ����ٰ� ���� 2���� �迭 �Է¿� �ͼ�ġ �ʾ�
//		���� C++�� Ǯ����.
int n, m;
char origin[10][10];
char trans[20][20];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> origin[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * m; j++) {
			cin >> trans[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * m; j++) {
			if (origin[i][j / 2] != trans[i][j]) {
				cout << "Not Eyfa" << endl;
				return 0;
			}
		}
	}

	cout << "Eyfa" << endl;
}