#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 17201번 자석 체인
// 분류: 이전값과 비교
// 문제:
//		이전 값과 같은 구간이 있으면 No, 없으면 Yes
// 풀이:
//		이전 값과 같으면 No, 끝까지 다 다르면 Yes
int main() {
	int n;
	cin >> n;
	string magnet;
	cin >> magnet;
	char before = magnet[0];
	for (int i = 1; i < 2 * n; i++) {
		if (before == magnet[i]) {
			cout << "No\n";
			return 0;
		}
		before = magnet[i];
	}
	cout << "Yes\n";
	return 0;
}