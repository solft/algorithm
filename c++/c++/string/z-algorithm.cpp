#include <iostream>
#include <algorithm>
using namespace std;

#define LENGTH 1000000 // 문자열 길이
int Z[LENGTH], L, R;

int main() {
	string S;
	cin >> S;
	int N = S.length();
	for (int i = 1; i < N; i++) {
		if (i > R) {
			L = R = i;
			while (R < N && S[R - L] == S[R]) R++;
			Z[i] = R - L;
			R--;
		}
		else {
			int k = i - L;
			if (Z[k] < R - i + 1) Z[i] = Z[k];
			else {
				L = i;
				while (R < N && S[R - L] == S[R]) R++;
				Z[i] = R - L;
				R--;
			}
		}
	}

	// 구한 Z 배열
	for (int i = 1; i < N; i++)
		cout << Z[i] << ' ';
	cout << '\n';
}

/*
응용
	1. 패턴 매칭
		ABCABABCA에서 ABC가 몇 번, 어디서 나오는지 체크하려면
		ABC#ABCABABCA #과 같이 사용되지 않는 문자를 추가해서 만든 문자열의
		Z 배열을 만들고 # 뒷부분의 값이 # 앞부분 길이면 나타나는 곳이다.
		ABC#ABCABABCA
		-000300203001 예제에서는 이렇게 나오고 나타나는 곳은 3이상인 2곳이고 위치는 0, 5번 인덱스다.
	2. 경계 찾기(팬린드롬)
		ABACABACABA에서 문자열의 길이를 n이라고 하면
		k + z[k] = n인 곳이 팬린드롬인 위치다.k는 인덱스
*/
