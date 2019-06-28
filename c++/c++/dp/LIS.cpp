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

	for (auto num : sequence) {
		if (lis.empty() || lis.back() < num)
			lis.push_back(num);
		else {
			auto insert_position = lower_bound(lis.begin(), lis.end(), num);
			*insert_position = num;
		}
	}

	for (auto s : lis)
		cout << s << ' ';
	cout << '\n';
}