#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;


// 17285�� XORChic
// �з�: xor
// ����:
//		key�� �𸣰� ���ڿ��� ���ڸ� key�� xor�� ���� ���ڿ���
//		ù 8�ڸ��� "CHICKENS"�϶� ��ȯ�� ���ڿ��� ����ϴ� ����
// Ǯ��:
//		ù 8�ڸ��� "CHICKENS"�� ����� key�� �ݺ������� ã��
//		��ȯ�� ����� ����Ѵ�.
int main() {
	char t[101];

	cin >> t;

	char key = 0;
	while (1) {
		if ((t[0] ^ key) == 'C')
			if ((t[1] ^ key) == 'H')
				if ((t[2] ^ key) == 'I')
					if ((t[4] ^ key) == 'K')
						if ((t[5] ^ key) == 'E')
							if ((t[6] ^ key) == 'N')
								if ((t[7] ^ key) == 'S')
									break;
		key++;
	}

	for (int i = 0; t[i] != '\0'; i++) {
		char out = t[i] ^ key;
		cout << out;
	}
	cout << '\n';
}