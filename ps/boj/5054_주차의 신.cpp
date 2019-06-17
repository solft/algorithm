#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 5054번 주차의 신
// 분류: 최댓값 최솟값
// 문제:
//		수직선 상 좌표가 여러개 주어지고 모든 좌표를 왔다갔다하는 최솟값을 구하는 문제
// 풀이:
//		2 * (최댓값 - 최솟값)
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n; 
		cin >> n;
		vector<int> store;
		store.resize(n);
		int min_pos = 1000000000;
		int max_pos = 0;
		for (int i = 0; i < n; i++) {
			cin >> store[i];
			if (min_pos > store[i])
				min_pos = store[i];
			if (max_pos < store[i])
				max_pos = store[i];
		}

		cout << 2 * (max_pos - min_pos) << '\n';
	}
}