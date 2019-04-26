#include <iostream>
using namespace std;

// 11383번 뚊
// 문제:
//		두 문자 배열을 입력받고 첫 문자 배열을 가로 방향으로 
//		2배하면 두 번째 문자 배열과 같은지 비교하는 간단 구현 문제
// 풀이:
//		2차원 문자 배열로 입력 받고 직접 다 비교해서 풀었다.
//		배열 사이즈가 작아 그냥 구현해도 아무 문제 없어 보인다.
//		go로 풀어보려다가 아직 2차원 배열 입력에 익숙치 않아
//		급히 C++로 풀었다.
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