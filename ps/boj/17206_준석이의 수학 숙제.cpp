#include <iostream>
using namespace std;

// 17206�� �ؼ����� ���� ����
// �з�: ����
// ����:
//		���� n ������ (3�� ���) + (7�� ���) ���ϱ�
// Ǯ��:
//		(3�ǹ��) + (7�ǹ��) - (21�ǹ��)
int n[100001];

int solution(int a) {
	// (���ǰ���*(����+����))/2
	int tree = ((a / 3) * (3 + 3 * (a / 3))) / 2;
	int seven = ((a / 7) * (7 + 7 * (a / 7))) / 2;
	int twentyone = ((a / 21) * (21 + 21 * (a / 21))) / 2;
	return tree + seven - twentyone;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		cin >> n[i];

	for (int i = 0; i < t; i++)
		cout << solution(n[i]) << '\n';
}
