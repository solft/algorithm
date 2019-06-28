#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

// LIS(Longest Increasing Subsequence) 최장 증가 수열
int main() {
	vector<int> sequence = { 1, 100, 2, 50, 60, 3, 5, 6, 7, 8 };
	vector<int> lis;

	for (auto s : sequence)
		cout << s << ' ';
	cout << '\n';

	// O(N^2)로 구하기
	vector<int> dp;
	vector<vector<int>> lisList;
	int n = sequence.size();
	dp.resize(n);
	lisList.resize(n);
	for (int i = 0; i < n; i++) {
		if (dp[i] == 0) dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (sequence[i] > sequence[j])
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					lisList[i] = lisList[j];
					lisList[i].push_back(sequence[i]);
				}
	}

	cout << "dp를 활용한 LIS 길이 = " << dp[n - 1] << '\n';
	for (auto k : lisList[n - 1])
		cout << k << ' ';
	cout << '\n';


	// 길이만 빠르게 찾기
	for (auto num : sequence) {
		if (lis.empty() || lis.back() < num)
			lis.push_back(num);
		else {
			auto insert_position = lower_bound(lis.begin(), lis.end(), num);
			*insert_position = num;
		}
	}

	cout << "lower_bound를 활용한 LIS 길이 = " << lis.size() << '\n';
}