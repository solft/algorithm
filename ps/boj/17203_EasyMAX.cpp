#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 17203번 ∑|ΔEasyMAX|
// 풀이: 구현
// 문제: 
//		구간이 주어지면 그 구간에서 1칸 변화량의 합을 구하는 문제
// 풀이:
//		1칸 변화량을 저장해두고 입력 받으면 그 구간합을 구한다.
int song[1010];
int diff[1010];

int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> song[i];
	for (int i = 1; i < n; i++)
		diff[i] = abs(song[i] - song[i - 1]);

	while (q--) {
		int a, b;
		cin >> a >> b;
		int ans = 0;

		for (int i = a; i < b; i++)
			ans += diff[i];
		cout << ans << '\n';
	}
}