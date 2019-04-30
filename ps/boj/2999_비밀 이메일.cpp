#include <iostream>
using namespace std; 

// 2999번 비밀 이메일
// 문제:
//		문자열이 주어지면 r*c 행렬에 상하 -> 좌우방식으로 한 문자씩 넣고
//		좌우 -> 상하 방식으로 읽은 결과를 출력하는 문제
// 풀이:
//		우선 r과 c를 문제에 주어진 조건대로 구하고
//		r과 c에 따라 1차원 문자열의 인덱스를 어떻게 변화시킬지 생각
//		한 row에서 수만큼 출력하므로 r안에 c가 있는 for문을 만들어 출력하면 된다.
int main() {
	string message;
	cin >> message;
	int n = message.length();
	int r = n;
	int c = 0;
	while (1) {
		if (n % r == 0 && r <= n / r) {
			c = n / r;
			break;
		}
		r--;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << message[i + j*r];
		}
	}
	cout << endl;
}