#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

// 12015번 12738번 가장 긴 증가하는 부분 수열 2, 3
// 분류: LIS
// 문제:
//		LIS를 구하는데 수열이 엄청 길어 O(n log n)의 시간 복잡도로 풀어야됨
// 풀이:
//		새 수가 들어갈 위치가 마지막이냐 lower_bound냐를 
//		이진 탐색으로 빠르게 구해 LIS를 업데이트하여 푼다.
int n;
int num[1000001];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	vector<int> lis;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (lis.empty() || lis.back() < num[i]) {
			lis.push_back(num[i]);
			ans++;
		}
		else {
			auto insert_position = lower_bound(lis.begin(), lis.end(), num[i]);
			*insert_position = num[i];
		}
	}
	printf("%d\n", ans);
}