#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 9237�� ����� �ʴ�
// �з�: ����
// ����:
//		��� ������ �� �ڶ�� �ϴ� �� �� ���ϱ�
// Ǯ��:
//		���� ���� �ɸ��� �������� �ɴ´�.
int main() {
	int n;
	vector<int> t;
	cin >> n;
	t.resize(n);
	for (int i = 0; i < n; i++)
		cin >> t[i];
	sort(t.begin(), t.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int temp = t[n - i - 1] + i + 2;
		if (ans < temp)
			ans = temp;
	}
	cout << ans << '\n';
}