#include <iostream>
using namespace std;

// 17211�� ���� �� ���� ��
// �з�: Ȯ��
// ����:
//		���� ���¿��� �������� ����� ��� �ٲ����� ���� Ȯ���� �־�����
//		n�� ���� ����� Ȯ���� ���ϴ� ����
// Ǯ��:
//		(i+1)�Ͽ� ��� ���� Ȯ�� = i�Ͽ� ��� ���� Ȯ�� * �������->��������� Ȯ�� + i�Ͽ� ��� �� ���� Ȯ�� * ��о�����->��������� Ȯ��
//		(i+1)�Ͽ� ��� �� ���� Ȯ�� = i�Ͽ� ��� ���� Ȯ�� * �������->��о������� Ȯ�� + i�Ͽ� ��� �� ���� Ȯ�� * ��о�����->��о������� Ȯ��
int main() {
	int n, feeling;
	cin >> n >> feeling;
	double happy_happy, happy_sad, sad_happy, sad_sad;
	cin >> happy_happy >> happy_sad >> sad_happy >> sad_sad;
	double mood[2][101];

	mood[feeling][0] = 1.0;
	mood[1 - feeling][0] = 0.0;

	for (int i = 0; i < n; i++) {
		mood[0][i + 1] = mood[0][i] * happy_happy + mood[1][i] * sad_happy;
		mood[1][i + 1] = mood[0][i] * happy_sad + mood[1][i] * sad_sad;
	}

	cout << int(mood[0][n]*1000 + 0.5) << '\n';
	cout << int(mood[1][n]*1000 + 0.5) << '\n';
}