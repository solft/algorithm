#include <iostream>
using namespace std;
typedef long long ll;

// 17210�� ������
// �з�: ��Ģ ã��
// ����:
//		���� ���� ��Ģ�� �־����� ��Ģ�� �°� ���� ����� ����ϰų�
//		������� ���ϸ� "Love is open door"�� ����ϴ� ����
// Ǯ��:
//		6 �̻��̸� ������ "Love is open door"�̰�
//		6 �̸��̸� ������ ���� �ȴ�.
int main() {
	ll n;
	cin >> n;
	int door;
	cin >> door;

	if (n >= 6LL) {
		cout << "Love is open door" << '\n';
	}
	else {
		for (ll i = 2LL; i <= n; i++) {
			door = 1 - door;
			cout << door << '\n';
		}
	}
}