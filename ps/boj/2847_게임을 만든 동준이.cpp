#include <iostream>
#include <queue>

using namespace std;

// 2847번 게임을 만든 동준이
// 분류: 최댓값
// 문제:
//		배열의 자리를 바꾸지 않고 오름차순으로 만드려면
//		각 요소를 몇 번 감소시켜야 하는지 구하는 문제
// 풀이:
//		뒤에서부터 줄어들어야 하므로 앞 값이 크면 차이+1 만큼 빼준다.
int n;
int level[101];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> level[i];

	int hardScore = level[n - 1];
	int ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (level[i] >= hardScore) {
			ans += level[i] - hardScore + 1;
			hardScore = hardScore - 1;
		}
		else {
			hardScore = level[i];
		}
	}
	cout << ans << '\n';
}