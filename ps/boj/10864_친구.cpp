#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 10864�� ģ��
// �з�: ����
// ����:
//		��� ����� ģ�� ���� ���ϴ� ����
// Ǯ��:
//		a, b�� �־����� a==b�� ���� ���� ���Դ� a, b�� ������ �����Ƿ�
//		a�� ģ�� ���� 1 ���� ��Ű�� b�� ģ�� ���� 1 ������Ų��.
int friends[1001];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		friends[a]++;
		friends[b]++;
	}
	for (int i = 1; i <= n; i++)
		cout << friends[i] << '\n';
}