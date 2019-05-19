#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

// 1937번 욕심쟁이 판다
// 분류: 정렬, DP
// 문제:
//		2차원 배열의 한 점에서 출발하여 
//		값이 높은 곳으로만 움질일때
//		가장 많이 움직이는 횟수를 구하는 문제
// 풀이:
//		2차원 배열의 값들을 다 벡터에 넣고
//		정렬해서 작은 값부터 출발해서 구해나간다.
//		몇가지 디테일을 챙기지 못해서 많이 틀렸다.
int forest[501][501];
int dp[501][501];
vector<pair<int, ii>> bamboo;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> forest[i][j];
			bamboo.push_back(make_pair(forest[i][j], ii(i, j)));
		}
	}
	sort(bamboo.begin(), bamboo.end());

	int mr[4] = { -1, 0, 1, 0 };
	int mc[4] = { 0, 1, 0, -1 };

	for (int i = 0; i < n*n; i++) {
		ii pos = bamboo[i].second;

		for (int j = 0; j < 4; j++) {
			if (pos.first + mr[j] >= 0 && pos.first + mr[j] < n && pos.second + mc[j] >= 0 && pos.second + mc[j] < n) {
				if (forest[pos.first][pos.second] > forest[pos.first+mr[j]][pos.second+mc[j]] 
					&& dp[pos.first][pos.second] < dp[pos.first + mr[j]][pos.second + mc[j]] + 1)
					dp[pos.first][pos.second] = dp[pos.first + mr[j]][pos.second + mc[j]] + 1;
			}				
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (dp[i][j] > ans)
				ans = dp[i][j];
	cout << ans + 1 << '\n';
}