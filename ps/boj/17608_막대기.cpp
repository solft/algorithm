#include <iostream>
using namespace std;

// 17608�� �����
// �з�: ī����
// ����:
//		���̰� �پ��� ���밡 �Ϸķ� ������ ���� ��,
//		�����ʿ��� �� ���� ���밡 ���̴��� ���� ����
// Ǯ��:
//		�����ʺ��� ���� �� ���븦 ���ϸ鼭 ī���� �Ѵ�.
int stick[100010];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stick[i];
	}

	int rightHigh = stick[n - 1];
	int ans = 1;

	for (int i = n - 2; i >= 0; i--) {
		if (rightHigh < stick[i]) {
			ans++;
			rightHigh = stick[i];
		}
	}

	cout << ans << '\n';
}