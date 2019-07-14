#include <iostream>
#include <stack>
using namespace std;

// 17173번 배수들의 합
// 분류: 수학
// 문제:
//		n이하의 숫자들 중 m개의 숫자 배수들을 다 더한 값을 구하는 문제
// 풀이:
//		1000까지 숫자이므로 충분히 작아서
//		배열로 있는 것들 체크해 두고 다 더했다.
//		배수 관계 생각하면 뒷부분 계산 안할것 체크해도 되는데 안해줬다.
int num[1001];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int c;
		cin >> c;
		for (int j = 1; j * c <= n; j++)
			num[j * c] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (num[i] == 1)
			ans += i;
	}

	cout << ans << '\n';
}