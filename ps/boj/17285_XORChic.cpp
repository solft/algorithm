#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;


// 17285번 XORChic
// 분류: xor
// 문제:
//		key를 모르고 문자열의 문자를 key와 xor한 후의 문자열의
//		첫 8자리가 "CHICKENS"일때 변환된 문자열을 출력하는 문제
// 풀이:
//		첫 8자리를 "CHICKENS"로 만드는 key를 반복문으로 찾고
//		변환한 결과를 출력한다.
int main() {
	char t[101];

	cin >> t;

	char key = 0;
	while (1) {
		if ((t[0] ^ key) == 'C')
			if ((t[1] ^ key) == 'H')
				if ((t[2] ^ key) == 'I')
					if ((t[4] ^ key) == 'K')
						if ((t[5] ^ key) == 'E')
							if ((t[6] ^ key) == 'N')
								if ((t[7] ^ key) == 'S')
									break;
		key++;
	}

	for (int i = 0; t[i] != '\0'; i++) {
		char out = t[i] ^ key;
		cout << out;
	}
	cout << '\n';
}