#include <iostream>
#include <cmath>
#include <vector>

// 5426번 비밀 편지
// 분류: 순서
// 문제:
//		문자열을 정사각형 배열에 넣고 오른쪽 열부터 내려가며 출력한다.
// 풀이:
//		전체길이-1에서 길이만큼 건너뛰며 출력하고
//		전체길이-1 에서 0까지 반복한다.
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;

		int len = int(sqrt(str.length()));
		for (int i = len-1; i >= 0; i--)
			for (int j = 0; j < len; j++)
				cout << str[len * j + i];
		cout << '\n';
	}
}