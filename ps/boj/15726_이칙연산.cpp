#include <iostream>
#include <cmath>

using namespace std;

// 15726�� ��Ģ����
// �з�: ����
// ����:
//		���ϰ� �����Ŷ� ������ ���ѰŶ� �� �߿� ���� �� ū�� ���ϴ� ����
// Ǯ��:
//		���ϰ� ���� ���� ������ ���� ���� ���ؼ�
//		ū ���� int ������(�����ؼ�) ����Ѵ�.
int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double md = a * b / c;
	double dm = a / b * c;
	if (md > dm)
		cout << int(md) << '\n';
	else
		cout << int(dm) << '\n';
}