#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;

// 4056번 스-스-스도쿠
// 분류: 브루트포스
// 문제:
//		스도쿠의 빈칸이 5군데 주어졌을 때 답을 구할수 있는지 찾고 찾은 답을 출력하는 문제
// 풀이:
//		각 빈칸에 들어 갈 수 있는 가능성 있는 수의 리스트를 구한다.(많아봐야 0~2개)
//		그리고 5중 반복문을 사용하여 모든 경우 중에 답이 되는 경우가 있는지 확인한다.
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
		// 선언
		int sudoku[9][9];
		vector<int> blank;
		//queue<int> blank;

		// 입력
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char num;
				cin >> num;
				sudoku[i][j] = num - '0';
				if (sudoku[i][j] == 0)
					blank.push_back(i * 9 + j);
			}
		}

		
		// 다시 풀기
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

		// 5중 반복
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

		// 결과
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