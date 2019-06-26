#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;


// 10090�� Counting Inversions
// �з�: inversion counting
// ����:
//		�������� �� ���� �� �� ������ �� ũ�� �ڰ� �� ���� ¦�� ������ ���ϴ� ����
//		inversion counting�� �⺻ �����̴�.
// Ǯ��:
//		merge sort�� �ϴ� �� merge �������� �������� �� �۾� �������� ���õǴ� ���
//		������ �����ִ� �κ��̶� ������ ���� �ϳ����� ���� inversion �� ���´�.
//		�׷��� �� ��Ȳ���� ���ʿ� �����ִ� ����ŭ inversion counting�� ���ش�.
// ���:
//		vector<int>�� ������ �ڵ�� �ð��ʰ��� ���� �迭�� �ٲ� �� 
//		���� ������ int�� �ѱ� ���� �����Ƿ� long long���� ���ְ� ����
//		�������� ���迭�� �����Ű�� merge�� ������ for���� �ȽἭ �̻��ϰ� Ʋ�ȴ�.
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