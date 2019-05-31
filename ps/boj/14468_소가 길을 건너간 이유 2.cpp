#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 114468�� �Ұ� ���� �ǳʰ� ����2
// �з�: ����
// ����:
//		�������� ���� ���ĺ����� ���� �׾��� ��
//		���� ��ġ�� ���� ����(������ ����)�� ���ϴ� ����
// Ǯ��:
//		���� ���ĺ� ���̿� �� ���� �ִ� �ٸ� ���ĺ��� ������ ������ �����.
//		��� ���ĺ��� ���� �� �� ī���� �ǹǷ� ������ �����ش�.
int main() {
	char load[52];
	for (int i = 0; i < 52; i++)
		cin >> load[i];

	int ans = 0;
	// A���� Z���� �˻�
	for (int i = 0; i < 26; i++) {

		int first = true;
		vector<int> count;
		count.assign(26, 0);

		for (int j = 0; j < 52; j++) {

			if (load[j] == 'A' + i) {
				if (first) {
					first = false;
				}
				else {
					break;
				}
			}
			else {
				if (!first) {
					count[load[j] - 'A']++;
				}
			}
		}
		
		for (auto c : count)
			if (c == 1)
				ans++;
	}
	cout << ans / 2 << '\n';
}
