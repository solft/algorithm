#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

// 2217번 로프
// 분류: 최대 규칙 찾기
// 문제:
//		최솟값 * 개수의 최댓값 구하기
// 풀이:
//		정렬을 하고 하나씩 늘려나가며 최소 * 개수의 최대를 찾는다
vector<int> rope;
int n;

int main() {
	cin >> n;
	rope.resize(n);
	for (int i = 0; i < n; i++)
		cin >> rope[i];
	sort(rope.begin(), rope.end());

	int ans = 0;
	int count = 0;
	for (int i = n - 1; i >= 0; i--) {
		count++;
		if (ans <= rope[i] * count) {
			ans = rope[i] * count;
		}
	}

	cout << ans << '\n';
}
