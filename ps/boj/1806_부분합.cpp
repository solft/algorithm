#include <iostream>
using namespace std;
// 1806번 부분합
// 분류: 합배열, 이진 탐색
// 문제:
//		배열에서 연속된 부분합들 중 특정 값 이상인 부분합의 최소 길이 구하기
// 풀이:
//		입력 받으며 합배열 만들고
//		찾으려는 길이를 이진 탐색으로 빠르게 찾는다.
//		(현재 길이에서 이상인거 찾으면 길이를 줄이고, 없으면 길이를 늘려서)
int n, s;
int num[100002];

int main() {
	cin >> n >> s;

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		num[i] += num[i - 1];
	}

	if (num[n] < s) {
		cout << 0 << endl;
		return 0;
	}
		

	int left = 1;
	int right = n;
	int mid; 
	int ans = n;

	while (left <= right) {
		mid = (left + right) / 2;

		int index = 0;
		while (index + mid <= n) {
			if (num[index + mid] - num[index] >= s) {
				if (ans > mid)
					ans = mid;
				right = mid - 1;
				break;
			}
			index++;
		}

		if (right != mid - 1) {
			left = mid + 1;
		}
	}
	cout << ans << endl;
}