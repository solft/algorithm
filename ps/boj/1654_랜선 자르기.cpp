#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

// 1654�� ���� �ڸ���
// �з�: �̺� Ž��
// ����:
//		���� ������ ������ �־����� �̸� �߶� �Ȱ��� ������ ���� k���� ������ �� ��
//		������� ������ �ִ� ���� ���ϴ� ����
// Ǯ��:
//		������ ������ ���̸� �̺� Ž������ ������ Ž���ϰ�
//		������ �ִ� ���̸� ����Ѵ�.
//		����! k�� �̻� ����� ��쿡�� ���� �ش�.
ll lan[10010];
int n, k;

int lanCount(int x) {
	int res = 0;
	for (int i = 0; i < n; i++)
		res += lan[i] / x;
	return res;
}

int main() {
	cin >> n >> k;
	
	ll left = 1;
	ll right = 0;
	for (int i = 0; i < n; i++) {
		cin >> lan[i];
		if (right < lan[i])
			right = lan[i];
	}
	

	ll mid = (left + right) / 2;
	ll ans = 0;
	while (left <= right) {
		int temp = lanCount(mid);
		if (temp >= k) { // �� ���� ���� �� �ִ� ��� => ���̸� �ø���.
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else if (temp < k) { // �� ���� ����� ��� => ���̸� ���δ�.
			right = mid - 1;
		}

		mid = (left + right) / 2;
	}
	cout << ans << '\n';
}
