#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

// 2477�� ���ܹ�
// �з�: ����
// ����:
//		���� 4�������� ���ư� ������ ���� �־��� ��
//		������ ���ϴ� ����
// Ǯ��:
//		���η� ���� �� ���� ���η� ���� �� ���� ���ϰ�
//		�� �� �ε������� 3��°�� ��Ÿ���� ���� ª�� �����̹Ƿ�
//		�̸� �̿��� ū �簢������ ���� �簢�� ���� ���̸� ���Ѵ�
pair<int, int> side[6];

int main() {
	int k;
	cin >> k;

	int long_x = 0;
	int x_index = 0;
	int long_y = 0;
	int y_index = 0;

	int short_x = 0;
	int short_y = 0;

	for (int i = 0; i < 6; i++) {
		cin >> side[i].first >> side[i].second;
		if (side[i].first <= 2) { // ����
			if (long_x < side[i].second) {
				long_x = side[i].second;
				x_index = i;
			}
		}
		else if (side[i].first > 2) { // ����
			if (long_y < side[i].second) {
				long_y = side[i].second;
				y_index = i;
			}
		}
	}

	short_y = side[(x_index + 3) % 6].second;
	short_x = side[(y_index + 3) % 6].second;

	cout << ((long_x * long_y) - (short_x * short_y)) * k << '\n';
}
