#include <iostream>
using namespace std; 

// 2999�� ��� �̸���
// ����:
//		���ڿ��� �־����� r*c ��Ŀ� ���� -> �¿������� �� ���ھ� �ְ�
//		�¿� -> ���� ������� ���� ����� ����ϴ� ����
// Ǯ��:
//		�켱 r�� c�� ������ �־��� ���Ǵ�� ���ϰ�
//		r�� c�� ���� 1���� ���ڿ��� �ε����� ��� ��ȭ��ų�� ����
//		�� row���� ����ŭ ����ϹǷ� r�ȿ� c�� �ִ� for���� ����� ����ϸ� �ȴ�.
int main() {
	string message;
	cin >> message;
	int n = message.length();
	int r = n;
	int c = 0;
	while (1) {
		if (n % r == 0 && r <= n / r) {
			c = n / r;
			break;
		}
		r--;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << message[i + j*r];
		}
	}
	cout << endl;
}