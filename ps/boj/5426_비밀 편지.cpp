#include <iostream>
#include <cmath>
#include <vector>

// 5426�� ��� ����
// �з�: ����
// ����:
//		���ڿ��� ���簢�� �迭�� �ְ� ������ ������ �������� ����Ѵ�.
// Ǯ��:
//		��ü����-1���� ���̸�ŭ �ǳʶٸ� ����ϰ�
//		��ü����-1 ���� 0���� �ݺ��Ѵ�.
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;

		int len = int(sqrt(str.length()));
		for (int i = len-1; i >= 0; i--)
			for (int j = 0; j < len; j++)
				cout << str[len * j + i];
		cout << '\n';
	}
}