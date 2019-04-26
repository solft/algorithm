#include <iostream>
#include <vector>
using namespace std;

// Bot saves princess
// ó�� ���� ������ ������.
// p, m ã�� �ݺ��� ����� �ص� �Ǵµ� �׳� ���״�.
void displayPathtoPrincess(int n, vector <string> grid) {
	int botX = 0, botY = 0;
	int princessX = 0, princessY = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 'p') {
				princessX = j;
				princessY = i;
			}
			if (grid[i][j] == 'm') {
				botX = j;
				botY = i;
			}
		}
	}

	int moveX = princessX - botX;
	int moveY = princessY - botY;

	while (moveY != 0) {
		if (moveY < 0) {
			cout << "UP" << endl;
			moveY++;
		}
		if (moveY > 0) {
			cout << "DOWN" << endl;
			moveY--;
		}
	}

	while (moveX != 0) {
		if (moveX < 0) {
			cout << "LEFT" << endl;
			moveX++;
		}
		if (moveX > 0) {
			cout << "RIGHT" << endl;
			moveX--;
		}
	}
}

int main(void) {

	int m;
	vector <string> grid;

	cin >> m;

	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		grid.push_back(s);
	}

	displayPathtoPrincess(m, grid);

	return 0;
}