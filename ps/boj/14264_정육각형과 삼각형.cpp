#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 14264�� ���������� �ﰢ��
// �з�: ����
// ����:
//		���������� �밢�� 3�� �׾� ���� ���� ���� �ﰢ���� ���� ���ϱ�
// Ǯ��:
//		������ ���� L�� ���ﰢ�� ũ���� �ﰢ���� ���� �����Ƿ�
//		���ﰢ�� ���� ������ (��Ʈ(3)/4)*(��*��) ���� ���Ѵ�.
int main() {
	int l;
	cout << fixed;
	cout.precision(15);
	
	cin >> l;
	cout << sqrt(3) / 4 * double(l) * double(l) << '\n';
}