#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

// 14002번 가장 긴 증가하는 부분 수열 4
// 분류: LIS
// 문제:
//		LIS를 구하고 LIS의 리스트도 출력하는 문제
// 풀이:
//		큰 사이즈는 세그먼트 트리를 이용해야하는데 사이즈가 작으므로 dp 이용
//		각 위치의 LIS가 업데이트 될 때 마다 LIS list도 추가하며 업데이트 해주었다.
//		그리고 마지막에 최장 LIS 길이와 똑같은 LIS list를 출력해주었다.
int main() {
	vector<int> sequence;

	int n;
	int ans = 1;
	cin >> n;
	sequence.resize(n);
	for (int i = 0; i < n; i++)
		cin >> sequence[i];

	// O(N^2)로 구하기
	vector<int> dp;
	vector<vector<int>> lisList;
	dp.resize(n, 0);
	lisList.resize(n);
	for (int i = 0; i < n; i++) {
		if (dp[i] == 0) {
			lisList[i].push_back(sequence[i]);
			dp[i] = 1;
		}
		for (int j = 0; j < i; j++)
			if (sequence[i] > sequence[j])
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					if (ans < dp[i])
						ans = dp[i];
					lisList[i] = lisList[j];
					lisList[i].push_back(sequence[i]);
				}
	}

	cout << ans << '\n';
	for (int i = 0; i < n; i++) {
		if (lisList[i].size() == ans) {
			for (auto s : lisList[i])
				cout << s << ' ';
			cout << '\n';
			break;
		}
	}
}