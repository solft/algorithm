#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 9237번 이장님 초대
// 분류: 정렬
// 문제:
//		모든 나무를 다 자라게 하는 날 수 구하기
// 풀이:
//		가장 오래 걸리는 나무부터 심는다.
int main() {
	int n;
	vector<int> t;
	cin >> n;
	t.resize(n);
	for (int i = 0; i < n; i++)
		cin >> t[i];
	sort(t.begin(), t.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int temp = t[n - i - 1] + i + 2;
		if (ans < temp)
			ans = temp;
	}
	cout << ans << '\n';
}