#include <iostream>
#include <algorithm>
using namespace std;

// 17273�� ī�� ����(Small)
// �з�: ����
// ����:
//		���̴¸� ���� ������ ������ ���� �ݺ��ϴٰ� �������� ���̴� �� ���
// Ǯ��:
//		������� �����Ѵ�.
int n, m;
int face[2];
int state = 0;
int k;

int main() {
	cin >> n >> m;
	cin >> face[0] >> face[1];
	while (m--) {
		cin >> k;
		if (k >= face[state])
			state = 1 - state;
	}
	cout << face[state] << '\n';
}