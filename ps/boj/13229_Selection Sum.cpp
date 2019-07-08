#include <iostream>
#include <cmath>

using namespace std;

// 13229�� Selection Sum
// �з�: �չ迭
// ����:
//		�ε��� start ~ end ������ �� ���ϱ�
// Ǯ��:
//		������ �迭�� ���� [end] - [start-1]�� �������� ������ ���Ѵ�.
int n, m, s, e;
int num[100001];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		num[i] += num[i - 1];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << (num[e+1] - num[s]) << '\n';
	}
}