#include <iostream>
#include <stack>
using namespace std;


// 1284번 집 주소
// 분류: 숫자 세기
// 문제:
//		1이면 3 더하고, 0이면 5 더하고 나머지는 4 더하는 문제
// 풀이:
//		자릿수 하나씩 뭔지 확인한다.
int solution(int num) {
	int result = 1;
	while (num > 0) {
		int now = num % 10;
		num /= 10;

		if (now == 1)
			result += 3;
		else if (now == 0)
			result += 5;
		else
			result += 4;
	}
	return result;
}

int main() {
	int n;
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		cout << solution(n) << '\n';
	}
}