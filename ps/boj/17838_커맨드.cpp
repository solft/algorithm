#include <iostream>
using namespace std;

// 17838번 커맨드
// 분류: 조건문
// 문제:
//		AABBABB 형태인지 구하는 문제
// 풀이:
//		길이가 7이 아니면 false
//		길이가 7이면 인덱스로 문자 비교
//		0, 1, 4 위치 같아야하고
//		2, 3, 5, 6 위치 같아야하며
//		둘은 서로 달라야 한다.
bool solution(string c) {
	if (c.length() != 7)
		return false;


	if (c[0] == c[1] && c[1] == c[4] && c[2] == c[3] && c[3] == c[5] && c[5] == c[6] && c[0] != c[6])
		return true;

	return false;
}

int main() {
	string command;
	int t;

	cin >> t;

	while (t--) {
		cin >> command;

		if (solution(command))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}