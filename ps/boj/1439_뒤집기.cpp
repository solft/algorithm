#include <iostream>
#include <vector>

using namespace std;

// 1439�� ������
// �з�: ��ȭ�� ī����
// ����:
//		���ӵ� ���� ���� ����� ��� ���� ���� ����� ���� ������ Ƚ�� ���ϴ� ����
// Ǯ��:
//		���ӵ� 0�� 1�� ������ ī���� �� �� ���� �� ��ŭ ������ ������ �ϸ� �ȴ�.
char s[1000001];

int main() {

	cin >> s;
	int counter[2] = { 0, 0 };

	char before = s[0];
	for (int i = 1; s[i] != '\0'; i++) {
		if (before != s[i]) {
			counter[before - '0']++;
			before = s[i];
		}
	}
	counter[before - '0']++;

	if (counter[0] < counter[1])
		cout << counter[0] << '\n';
	else
		cout << counter[1] << '\n';

}