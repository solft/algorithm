#include <iostream>
#include <queue>

using namespace std;

// 2847�� ������ ���� ������
// �з�: �ִ�
// ����:
//		�迭�� �ڸ��� �ٲ��� �ʰ� ������������ �������
//		�� ��Ҹ� �� �� ���ҽ��Ѿ� �ϴ��� ���ϴ� ����
// Ǯ��:
//		�ڿ������� �پ���� �ϹǷ� �� ���� ũ�� ����+1 ��ŭ ���ش�.
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