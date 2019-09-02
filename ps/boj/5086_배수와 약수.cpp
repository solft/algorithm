#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 5086번 배수와 약수
// 분류: %
// 문제:
//		첫 수가 두번째 수의 배수인지 약수인지 구하는 문제
// 풀이:
//		% 연산 해본다.

int main() {
	int a, b;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			break;

		if (a % b == 0)
			printf("multiple\n");
		else if (b % a == 0)
			printf("factor\n");
		else
			printf("neither\n");
	}
}