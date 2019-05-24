#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 1233번 주사위
// 분류: 반복문
// 문제:
//		주사위 3개가 나오면 가장 많이 나오는 주사위 눈을 구하는 문제
// 풀이:
//		많아 봐야 20*20*30 번 반복문이여서 브루트포스로 다 구했다.
int dice[100];

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			for (int k = 1; k <= c; k++)
				dice[i + j + k]++;

	int m = 0;
	int ans = 0;

	for (int i = 3; i <= a + b + c; i++) {
		if (dice[i] > m) {
			m = dice[i];
			ans = i;
		}
	}

	cout << ans << '\n';
}