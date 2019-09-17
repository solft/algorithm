#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 2630�� ������ �����
// �з�: ��������
// ����:
//		���簢�� ����� ���� ���� ��ġ�� �� �� ���� ���� ����
// Ǯ��:
//		Ư�� ����� ���� ������ ī��Ʈ ������Ű��
//		�ٸ��� �����ؼ� �ݺ��Ѵ�.
int n;
int paper[130][130];
int blue = 0;
int white = 0;

void solution(int y, int x, int size) {

	int now = paper[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (paper[i][j] != now) {
				now = -1;
				break;
			}
		}
		if (now == -1)
			break;
	}

	if (now == 0)
		white++;
	else if (now == 1)
		blue++;
	else {
		int half = size / 2;
		solution(y, x, half);
		solution(y + half, x, half);
		solution(y, x + half, half);
		solution(y + half, x + half, half);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];

	solution(0, 0, n);
	cout << white << '\n' << blue << '\n';
}