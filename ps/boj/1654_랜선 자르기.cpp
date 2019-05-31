#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

// 1654번 랜선 자르기
// 분류: 이분 탐색
// 문제:
//		여러 길이의 랜선이 주어지고 이를 잘라 똑같은 길이의 랜선 k개를 만들어야 할 때
//		만들어진 랜선의 최대 길이 구하는 문제
// 풀이:
//		구해진 랜선의 길이를 이분 탐색으로 끝까지 탐색하고
//		가능한 최대 길이를 출력한다.
//		주의! k개 이상 만드는 경우에도 따져 준다.
ll lan[10010];
int n, k;

int lanCount(int x) {
	int res = 0;
	for (int i = 0; i < n; i++)
		res += lan[i] / x;
	return res;
}

int main() {
	cin >> n >> k;
	
	ll left = 1;
	ll right = 0;
	for (int i = 0; i < n; i++) {
		cin >> lan[i];
		if (right < lan[i])
			right = lan[i];
	}
	

	ll mid = (left + right) / 2;
	ll ans = 0;
	while (left <= right) {
		int temp = lanCount(mid);
		if (temp >= k) { // 더 많이 만들 수 있는 경우 => 길이를 늘린다.
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else if (temp < k) { // 더 적게 만드는 경우 => 길이를 줄인다.
			right = mid - 1;
		}

		mid = (left + right) / 2;
	}
	cout << ans << '\n';
}
