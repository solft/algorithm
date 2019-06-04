#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

// 4493번 가위 바위 보?
// 분류: 조건문
// 문제:
//		가위바위보 승자 구하기
// 풀이:
//		그냥 조건을 줘서 구했다.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int player1 = 0;
		int player2 = 0;
		int n;
		cin >> n;
		while (n--) {
			char p1, p2;
			cin >> p1 >> p2;
			if (p1 == 'P') {
				if (p2 == 'R')
					player1++;
				if (p2 == 'S')
					player2++;
			}
			else if (p1 == 'R') {
				if (p2 == 'S')
					player1++;
				if (p2 == 'P')
					player2++;
			}
			else if (p1 == 'S') {
				if (p2 == 'R')
					player2++;
				if (p2 == 'P')
					player1++;
			}
		}

		if (player1 > player2)
			cout << "Player 1\n";
		else if (player1 < player2)
			cout << "Player 2\n";
		else
			cout << "TIE\n";
	}
}
