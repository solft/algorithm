#include <iostream>
using namespace std;
// 10703번 유성
// 분류: 행렬
// 문제:
//		땅과 유성이 주어졌을때 각 열들 중 최소거리 찾기
// 풀이:
//		최소거리를 찾으려면 일단 X(유성)이 있어야하고
//		그 다음부터 .이면 증가시키다가 다시 X(유성)이 나오면 .개수는 0부터 시작하고
//		#(땅)이 나오면 멈춘다.
//		유성 없을 때 처리를 안해줘서 한 번 틀렸다.
char photo[3000][3000];
char result[3000][3000];
int r, s;

int main() {
	cin >> r >> s;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < s; j++)
			cin >> photo[i][j];

	int minAir = s + 1;

	for (int j = 0; j < s; j++) {
		int colAir = 0;
		int hasX = false;
		for (int i = 0; i < r; i++) {
			if (photo[i][j] == 'X') {
				hasX = true;
				colAir = 0;
				continue;
			}
			else if (photo[i][j] == '.')
				colAir++;
			else if (photo[i][j] == '#')
				break;
		}
//		cout << "colAir = " << colAir << endl;
		if (hasX && minAir > colAir)
			minAir = colAir;
	}

//	printf("Input TEST: \n");
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < s; j++) {
//			cout << photo[i][j];
//		}
//		cout << '\n';
//	}
//	cout << minAir << endl;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			if (photo[i][j] == 'X')
				result[i + minAir][j] = 'X';
			else if (photo[i][j] == '#')
				result[i][j] = '#';
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			if (result[i][j] == 0)
				cout << '.';
			else
				cout << result[i][j];
		}
		cout << '\n';
	}
}