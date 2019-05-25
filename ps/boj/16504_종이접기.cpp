#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

// 16504번 종이접기
// 분류: 구현
// 문제:
//		배열에 숫자가 주어지고 정확히 반으로 나눌수 있을 때 세로로, 가로로
//		접어서 겹치는 부분 더하고 이를 할 수 있을 때 까지 반복 후 결과를 출력
// 풀이:
//		가로나 세로가 짝수일 때 반으로 접어서 더해주고 이를 가능할 때까지 직접 구한다.
typedef long long ll;
ll a[1024][1024];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	int ga = n;
	int se = n;

	while (ga % 2 == 0 && se % 2 == 0) {
		if (ga % 2 == 0) {
			ga /= 2;
			for (int i = 0; i < se; i++)
				for (int j = 0; j < ga; j++)
					a[i][j] += a[i][ga * 2 - j - 1];
		}

		if (se % 2 == 0) {
			se /= 2;
			for (int i = 0; i < ga; i++)
				for (int j = 0; j < se; j++)
					a[j][i] += a[se * 2 - j - 1][i];
		}
	}

	for (int i = 0; i < se; i++) {
		for (int j = 0; j < ga; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}