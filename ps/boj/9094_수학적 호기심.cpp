#include <iostream>

using namespace std;

// 9094번 수학적 호기심
// 분류: 반복문
// 문제:
//		(a^2+b^2+m)/(ab)가 정수인 쌍 (a, b) 찾기 조건. 0 < a < b < n
// 풀이:
//		범위가 100 이하이므로 브루트포스로 직접 구해본다.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		int ans = 0;
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (((i * i) + (j * j) + m) % (i * j) == 0)
					ans++;

		cout << ans << '\n';
	}
}