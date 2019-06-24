#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 12845�� ����� ����
// �з�: �ִ�
// ����:
//		���ڵ��� ���İ��� �ϳ��� ���鶧 ���� ������ �ִ� ���ϱ�
// Ǯ��:
//		�ִ� * (n-1) + ������
int n;
int card[1001];
int ans = 0;

int main() {
	cin >> n;
	int max_val = 0;
	int max_idx = 0;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
		if (max_val < card[i]) {
			max_val = card[i];
			max_idx = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (max_idx == i)
			continue;
		ans += card[i];
	}
	ans += (n - 1) * max_val;
	cout << ans << '\n';
}