#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 2502번 떡 먹는 호랑이
// 분류: 방정식
// 문제:
//		피보나치[d] * a + 피보나치[d+1] * b == k인 a와 b를 구하는 문제
// 풀이:
//		피보나치 수열을 30까지 구해두고 a, b를 b 먼저 증가시켜보며 찾는다.
//		없으면 a를 증가시키고 다시 b를 바꿔 계속 찾다가 만족하면 출력한다.
int a[31];
int b[31];

int main() {
	a[1] = 1;
	a[2] = 0;
	a[3] = 1;
	b[1] = 0;
	b[2] = 1;
	b[3] = 1;

	for (int i = 4; i <= 30; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}
	
	int d, k;
	cin >> d >> k;

	for (int i = 1; a[d] * i <= k; i++) {
		for (int j = 1; a[d] * i + b[d] * j <= k; j++) {
			if (a[d] * i + b[d] * j == k) {
				cout << i << '\n' << j << '\n';
				return 0;
			}
		}
	}
}