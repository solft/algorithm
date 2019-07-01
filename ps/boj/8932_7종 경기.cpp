#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 8932�� 7�� ���
// �з�: ����
// ����:
//		������ �־��� ������ ������ ���� ���ϱ�
// Ǯ��:
//		���ǿ� �°� �����ָ� �ȴ�.
int main() {
	double a[7] = { 9.23076,1.84523,56.0211,4.99087,0.188807,15.9803,0.11193 };
	double b[7] = { 26.7,75,1.5,42.5,210.,3.8,254 };
	double c[7] = { 1.835,1.348,1.05,1.81,1.41,1.04,1.88 };

	int t;
	cin >> t;
	while (t--) {
		double p[7];
		bool isTrack[7] = { true,false,false,true,false,false,true };
		for (int i = 0; i < 7; i++)
			cin >> p[i];

		int ans = 0;

		for (int i = 0; i < 7; i++) {
			if (isTrack[i])
				ans += a[i] * (pow(b[i] - p[i], c[i]));
			else
				ans += a[i] * (pow(p[i] - b[i], c[i]));
		}

		cout << ans << '\n';
	}
}