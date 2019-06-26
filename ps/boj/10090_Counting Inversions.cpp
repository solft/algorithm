#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;


// 10090번 Counting Inversions
// 분류: inversion counting
// 문제:
//		수열에서 두 개를 고를 때 앞쪽이 더 크고 뒤가 더 작은 짝의 개수를 구하는 문제
//		inversion counting의 기본 문제이다.
// 풀이:
//		merge sort를 하는 데 merge 과정에서 오른쪽이 더 작아 오른쪽이 선택되는 경우
//		왼쪽의 남아있는 부분이랑 오른쪽 들어가는 하나랑은 전부 inversion 한 상태다.
//		그래서 이 상황에서 왼쪽에 남아있는 수만큼 inversion counting을 해준다.
// 비고:
//		vector<int>로 구현한 코드는 시간초과가 나고 배열로 바꾼 뒤 
//		답의 범위가 int를 넘길 수도 있으므로 long long으로 써주고 나서
//		마지막에 원배열에 적용시키는 merge의 마지막 for문을 안써서 이상하게 틀렸다.
int n;
int permutation[1000001];
int temp[1000001];
ll ans = 0;

void merge(int left, int mid, int right) {
	int a = left, b = mid + 1;

	for (int i = left; i <= right; i++) {
		if (a > mid)
			temp[i] = permutation[b++];
		else if (b > right)
			temp[i] = permutation[a++];
		else if (permutation[a] <= permutation[b])
			temp[i] = permutation[a++];
		else if (permutation[a] > permutation[b]) {
			ans += ll(mid - a + 1);
			temp[i] = permutation[b++];
		}
	}

	for (int i = left; i <= right; i++)
		permutation[i] = temp[i];
}

void mergeSort(int left, int right) {
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	merge(left, mid, right);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &permutation[i]);
	mergeSort(0, n - 1);
	printf("%lld\n", ans);
}