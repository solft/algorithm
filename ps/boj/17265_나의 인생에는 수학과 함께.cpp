#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 17265�� ���� �λ����� ���а� �Բ�
// �з�: DP?
// ����:
//		�׷����� ������ or �Ʒ������� ���󰡸� ����� ����� �ִ�,�ּ� ���ϴ� ����
// Ǯ��:
//		��� ������ ��ġ(r, c ���� ¦���� ��)���� ������ �������� ������ �� ��
//		���� ��ġ�� ���� ������Ʈ �Ѵ�. (�ִ�, �ּҷ�) �׷��� n-1�� n-1�࿡ 
//		�ִ�, �ּҰ� ����ȴ�.
int n;
char world[5][5];
int max_val[5][5];
int min_val[5][5];

int eval(int a, char ope, int b) {
	if (ope == '+')
		return a + b;
	else if (ope == '-')
		return a - b;
	else if (ope == '*')
		return a * b;
	else
		return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> world[i][j];
			if ((i + j) % 2 == 0)
				min_val[i][j] = 1000000000;
				max_val[i][j] = -1000000000;
		}
	
	min_val[0][0] = max_val[0][0] = world[0][0] - '0';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i * 2; j++) {
			int r = j;
			int c = 2 * i - j;
			
			// rr ���
			if (c + 2 < n) {
				max_val[r][c + 2] = max(max_val[r][c + 2], eval(max_val[r][c], world[r][c + 1], world[r][c + 2] - '0'));
				min_val[r][c + 2] = min(min_val[r][c + 2], eval(min_val[r][c], world[r][c + 1], world[r][c + 2] - '0'));
			}
			// rd, dr ���
			if (r + 1 < n && c + 1 < n) {
				int max_temp = max(eval(max_val[r][c], world[r][c + 1], world[r + 1][c + 1] - '0'),
					eval(max_val[r][c], world[r + 1][c], world[r + 1][c + 1] - '0'));
				max_val[r + 1][c + 1] = max(max_val[r + 1][c + 1], max_temp);
				int min_temp = min(eval(min_val[r][c], world[r][c + 1], world[r + 1][c + 1] - '0'),
					eval(min_val[r][c], world[r + 1][c], world[r + 1][c + 1] - '0'));
				min_val[r + 1][c + 1] = min(min_val[r + 1][c + 1], min_temp);
			}
			// dd ���
			if (r + 2 < n) {
				max_val[r + 2][c] = max(max_val[r + 2][c], eval(max_val[r][c], world[r + 1][c], world[r + 2][c] - '0'));
				min_val[r + 2][c] = min(min_val[r + 2][c], eval(min_val[r][c], world[r + 1][c], world[r + 2][c] - '0'));
			}
		}
	}

	cout << max_val[n - 1][n - 1] << ' ' << min_val[n - 1][n - 1] << '\n';
}