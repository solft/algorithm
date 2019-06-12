#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 1041번 주사위
// 분류: 수학, 최솟값 찾기
// 문제:
//		주사위를 바닥에 놓았을 때 보이는 면의 최솟값을 구하는 문제
// 풀이:
//		1면, 2면, 3면의 최솟값 구하고 바닥에 놓았을 때 보이는 면의 수를 각각 곱해준다.
typedef long long ll;
#define INF 100000000
ll n;
ll a[6];

ll find_one_min() {
	ll result = INF;
	for (int i = 0; i < 6; i++)
		if (result > a[i])
			result = a[i];
	return result;
}

ll find_two_min() {
	ll result = INF;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == j || i + j == 5) // 같은 면끼리 더하거나 반대편 면끼리 더하는 경우
				continue;
			ll temp = a[i] + a[j];
			if (result > temp)
				result = temp;
		}
	}
	return result;
}

ll find_three_min() {
	ll result = INF;
	// ABC, ACE, AED, ABD
	if (result > a[0] + a[1] + a[2])
		result = a[0] + a[1] + a[2];
	if (result > a[0] + a[1] + a[3])
		result = a[0] + a[1] + a[3];
	if (result > a[0] + a[2] + a[4])
		result = a[0] + a[2] + a[4];
	if (result > a[0] + a[3] + a[4])
		result = a[0] + a[3] + a[4];
	// FBC, FCE, FED, FBD
	if (result > a[5] + a[1] + a[2])
		result = a[5] + a[1] + a[2];
	if (result > a[5] + a[1] + a[3])
		result = a[5] + a[1] + a[3];
	if (result > a[5] + a[2] + a[4])
		result = a[5] + a[2] + a[4];
	if (result > a[5] + a[3] + a[4])
		result = a[5] + a[3] + a[4];
	return result;
}

int main() {
	cin >> n;
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	// n == 1 일 경우
	// 밑부분 : 가장 큰 면이 밑면으로 가게끔
	if (n == 1) {
		ll ans = 0;
		ll die_max = 0;
		for (int i = 0; i < 6; i++) {
			ans += a[i];
			if (die_max < a[i])
				die_max = a[i];
		}
		cout << ans - die_max << '\n';
	}
	// n == 2 일 경우 
	// 윗부분 : 3면의 합이 가장 작은 경우 * 4
	// 밑부분 : 2면의 합이 가장 작은 경우 * 4
	else if (n == 2) {
		cout << find_three_min() * 4LL + find_two_min() * 4LL << '\n';
	}
	// n >= 3 일 경우 
	// 윗부분 : 3면의 합이 가장 작은 경우 * 4 + 2면의 합이 가장 작은 경우 * (n-2) * 8 + 가장 작은 면 * (n-2)*(n-2) * 5
	// 밑부분 : 2면의 합이 가장 작은 경우 * 4 + 가장 작은 면 * (n-2) * 4
	else if (n >= 3) {
		cout << find_three_min() * 4LL + find_two_min() * (8LL * n - 12LL) + find_one_min() * (5LL * n * n - 16LL * n + 12LL) << '\n';
	}
}