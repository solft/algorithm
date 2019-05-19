#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

// 1937�� ������� �Ǵ�
// �з�: ����, DP
// ����:
//		2���� �迭�� �� ������ ����Ͽ� 
//		���� ���� �����θ� �����϶�
//		���� ���� �����̴� Ƚ���� ���ϴ� ����
// Ǯ��:
//		2���� �迭�� ������ �� ���Ϳ� �ְ�
//		�����ؼ� ���� ������ ����ؼ� ���س�����.
//		��� �������� ì���� ���ؼ� ���� Ʋ�ȴ�.
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