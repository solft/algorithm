#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 14568�� 2017 �������б� ���α׷��� ��ô�ȸ
// �з�: ����� ��
// ����:
//		���� + ���� + ���� = n �̰�
//		����� ¦��, ���� >= ���� + 2 �� ����� �� ���ϱ�
// Ǯ��:
//		����� ���� ���� �����ش�.
int main() {
	int n;
	cin >> n;
	int ans = 0;
	int young, taek;
	taek = 2;
	while (n - taek >= 4) {
		young = 1;
		while (n - taek - young >= young + 2) {
			ans++;
			young++;
		}
		taek += 2;
	}
	cout << ans << '\n';
}