#include <iostream>
using namespace std;

// 11557 Yangjojang of the year
// �з�: �ִ� ���ϱ�
// ����:
//		�Է� ������ �� ���� ���� ���� �б� ����ϱ�
// Ǯ��:
//		�ִ밡 ���ĵ� �� �̸��� �����Ѵ�.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		string school;
		int alcohol;

		int maxAl = 0;
		string maxSchool = "";
		for (int i = 0; i < n; i++) {
			cin >> school >> alcohol;

			if (maxAl < alcohol) {
				maxAl = alcohol;
				maxSchool = school;
			}
		}
		cout << maxSchool << endl;
	}

}