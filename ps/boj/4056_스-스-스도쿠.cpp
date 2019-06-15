#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;

// 4056�� ��-��-������
// �з�: ���Ʈ����
// ����:
//		�������� ��ĭ�� 5���� �־����� �� ���� ���Ҽ� �ִ��� ã�� ã�� ���� ����ϴ� ����
// Ǯ��:
//		�� ��ĭ�� ��� �� �� �ִ� ���ɼ� �ִ� ���� ����Ʈ�� ���Ѵ�.(���ƺ��� 0~2��)
//		�׸��� 5�� �ݺ����� ����Ͽ� ��� ��� �߿� ���� �Ǵ� ��찡 �ִ��� Ȯ���Ѵ�.
int colCheck(int s[][9], int c) {
	set<int> potential = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 9; i++)
		potential.erase(s[i][c]);

	if (potential.size() == 0)
		return 0;
	else
		return -1;
}

int rowCheck(int s[][9], int r) {
	set<int> potential = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 9; i++)
		potential.erase(s[r][i]);

	if (potential.size() == 0)
		return 0;
	else
		return -1;
}

int blockCheck(int s[][9], int r, int c) {
	set<int> potential = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			potential.erase(s[r + i] [c + j]);

	if (potential.size() == 0)
		return 0;
	else
		return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		// ����
		int sudoku[9][9];
		vector<int> blank;
		//queue<int> blank;

		// �Է�
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char num;
				cin >> num;
				sudoku[i][j] = num - '0';
				if (sudoku[i][j] == 0)
					blank.push_back(i * 9 + j);
			}
		}

		
		// �ٽ� Ǯ��
		vector<vector<int>> blankList;
		blankList.resize(5);
		for (int i = 0; i < 5; i++) {
			int pos = blank[i];
			int r = pos / 9;
			int c = pos % 9;
			int br = r / 3;
			int bc = c / 3;

			int potential[10] = { 0,0,0,0,0,0,0,0,0,0 };
			for (int j = 0; j < 9; j++) {
				potential[sudoku[r][j]]++;
				potential[sudoku[j][c]]++;
				potential[sudoku[(br*3)+j/3][(bc*3)+j%3]]++;
			}
			for (int j = 1; j <= 9; j++) {
				if(potential[j] == 0)
					blankList[i].push_back(j);
			}
		}

		// 5�� �ݺ�
		bool possible = false;
		for (auto a : blankList[0]) {
			sudoku[blank[0] / 9][blank[0] % 9] = a;
			for (auto b : blankList[1]) {
				sudoku[blank[1] / 9][blank[1] % 9] = b;
				for (auto c : blankList[2]) {
					sudoku[blank[2] / 9][blank[2] % 9] = c;
					for (auto d : blankList[3]) {
						sudoku[blank[3] / 9][blank[3] % 9] = d;
						for (auto e : blankList[4]) {
							sudoku[blank[4] / 9][blank[4] % 9] = e;
							// check
							bool check = true;
							for (int k = 0; k < 9; k++) {
								if (colCheck(sudoku, k) != 0) {
									check = false;
									break;
								}
								if (rowCheck(sudoku, k) != 0) {
									check = false;
									break;
								}
								if (blockCheck(sudoku, (k / 3) * 3, (k % 3) * 3) != 0) {
									check = false;
									break;
								}
							}

							if (check) {
								possible = true;
								break;
							}
						}
						if (possible)
							break;
					}
					if (possible)
						break;
				}
				if (possible)
					break;
			}
			if (possible)
				break;
		}

		// ���
		if (possible) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					cout << sudoku[i][j];
				}
				cout << '\n';
			}
		}
		else {
			cout << "Could not complete this grid.\n";
		}
		cout << '\n';
	}
}