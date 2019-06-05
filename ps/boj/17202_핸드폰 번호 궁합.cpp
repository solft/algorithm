#include <iostream>
using namespace std;

// 17202번 핸드폰 번호 궁합
// 분류: 반복문
// 문제:
//		인접한 배열 더해나가다가 마지막 남은 2자리 출력하는 문제
// 풀이:
//		반복문으로 하나씩 줄여나가며 더해 나가다가 2개 남은 결과를 출력한다
int main() {
	int phone[20];

	for (int i = 1; i <= 8; i++) {
		char p;
		cin >> p;
		phone[2 * i - 1] = p - '0';
	}
		
	for (int i = 1; i <= 8; i++) {
		char p;
		cin >> p;
		phone[2 * i] = p - '0';
	}
		
	int size = 16;
	while (size > 2) {
		for (int i = 2; i <= size; i++)
			phone[i - 1] = (phone[i - 1] + phone[i])%10;
		size--;
	}
	cout << char(phone[1]+'0') << char(phone[2]+'0') << '\n';
}
