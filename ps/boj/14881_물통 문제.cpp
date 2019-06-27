#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 14881번 물통 문제
// 분류: GCD
// 문제:
//		용량 a, b짜리 물통으로 c를 만들수 있는지 묻는 문제
// 풀이:
//		gcd(a, b)의 배수들이 a, b로 만들수 있는 용량들이다.
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int g = a > b ? gcd(a, b) : gcd(b, a);
		if (c <= max(a, b) && c % g == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}