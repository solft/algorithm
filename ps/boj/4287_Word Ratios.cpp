#include <iostream>
using namespace std;

// 4287�� Word Ratios
// ����:
//		�� ���� ������ ��ȭ ��Ģ�� ã�� �ٸ� �� ���ڿ� �����Ű�� ����
// Ǯ��:
//		a[i] : b[i] = c[i] : ��[i] �̹Ƿ�
//		a[i] - b[i] = c[i] - ��[i]
//		��[i] = c[i] - a[i] + b[i]
//		���⼭ ��[i]�� 'a' ~ 'z' ������ ����� ��� �������ָ� �ȴ�.
// ����:
//		char�� ��� ���� ������ �ϸ� ������ ������ ��� ������ �Ǵ�
//		��찡 ������ ���� ���ϰ� int�� ��� char�� ��ȯ�� ����Ͽ���.
int main() {
	string a, b, c;
	while (true) {
		cin >> a;
		if (a == "#")
			break;
		cin >> b >> c;

		cout << a << " " << b << " " << c << " ";

		for (int i = 0; i < a.length(); i++) {
			int res = c[i] + b[i] - a[i];
			if (res > 'z')
				res -= 26;
			else if (res < 'a')
				res += 26;
			cout << char(res);
		}
		cout << endl;
	}
}