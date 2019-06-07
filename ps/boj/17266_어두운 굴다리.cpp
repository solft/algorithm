#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// 17266번 어두운 굴다리
// 분류: 큰 값 찾기
// 문제:
//		처음과 마지막은 그대로 중간은 절반만큼의 길이들 중 가장 큰 값을 찾기
// 풀이:
//		첫입력과 마지막입력은 그대로 따지고 중간의 경우 홀수일 경우 1 크게 짝수일 경우 그대로
int main() {
	int ans = 0;
	int n, m;
	cin >> n >> m;
	int before = 0;
	for (int i = 0; i < m; i++) {
		int pos;
		cin >> pos;

		if (i == 0) {
			if (ans < pos)
				ans = pos;
			before = pos;
		}
		else {
			if (ans < (pos - before + 1) / 2)
				ans = (pos - before + 1) / 2;
			before = pos;
		}
	}

	if (ans < n - before)
		ans = n - before;
	cout << ans << '\n';
}
