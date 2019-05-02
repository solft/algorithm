#include <iostream>
#include <utility>
#include <cmath>
using namespace std; 

// 3041�� N-����
// ����:
//		����ư �Ÿ� ���ϱ� ����
// Ǯ��:
//		���ĺ��� A~O���� �����Ƿ�
//		���� ��ġ�� ���� �����صΰ�
//		�Է����� ���� �迭�� ���ĺ��� ����
//		����ư �Ÿ��� �信 �����༭ Ǭ��.
char puzzle[4][4];
pair<int, int> point[15] = {
	pair<int, int>(0, 0),
	pair<int, int>(0, 1),
	pair<int, int>(0, 2),
	pair<int, int>(0, 3),
	pair<int, int>(1, 0),
	pair<int, int>(1, 1),
	pair<int, int>(1, 2),
	pair<int, int>(1, 3),
	pair<int, int>(2, 0),
	pair<int, int>(2, 1),
	pair<int, int>(2, 2),
	pair<int, int>(2, 3),
	pair<int, int>(3, 0),
	pair<int, int>(3, 1),
	pair<int, int>(3, 2)
};

int main() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> puzzle[i][j];
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (puzzle[i][j] != '.') {
				ans += abs(point[puzzle[i][j] - 'A'].first - i);
				ans += abs(point[puzzle[i][j] - 'A'].second - j);
			}
		}
	}
	cout << ans << endl;
}