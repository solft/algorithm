#include <iostream>
#include <algorithm>
using namespace std;

// 17273번 카드 공장(Small)
// 분류: 구현
// 문제:
//		보이는면 보다 작으면 뒤집어 가며 반복하다가 마지막에 보이는 수 출력
// 풀이:
//		문제대로 구현한다.
int n, m;
int face[2];
int state = 0;
int k;

int main() {
	cin >> n >> m;
	cin >> face[0] >> face[1];
	while (m--) {
		cin >> k;
		if (k >= face[state])
			state = 1 - state;
	}
	cout << face[state] << '\n';
}