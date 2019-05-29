#include <iostream>
#include <algorithm>
using namespace std;

#define LENGTH 1000000 // ���ڿ� ����
int Z[LENGTH], L, R;

int main() {
	string S;
	cin >> S;
	int N = S.length();
	for (int i = 1; i < N; i++) {
		if (i > R) {
			L = R = i;
			while (R < N && S[R - L] == S[R]) R++;
			Z[i] = R - L;
			R--;
		}
		else {
			int k = i - L;
			if (Z[k] < R - i + 1) Z[i] = Z[k];
			else {
				L = i;
				while (R < N && S[R - L] == S[R]) R++;
				Z[i] = R - L;
				R--;
			}
		}
	}

	// ���� Z �迭
	for (int i = 1; i < N; i++)
		cout << Z[i] << ' ';
	cout << '\n';
}

/*
����
	1. ���� ��Ī
		ABCABABCA���� ABC�� �� ��, ��� �������� üũ�Ϸ���
		ABC#ABCABABCA #�� ���� ������ �ʴ� ���ڸ� �߰��ؼ� ���� ���ڿ���
		Z �迭�� ����� # �޺κ��� ���� # �պκ� ���̸� ��Ÿ���� ���̴�.
		ABC#ABCABABCA
		-000300203001 ���������� �̷��� ������ ��Ÿ���� ���� 3�̻��� 2���̰� ��ġ�� 0, 5�� �ε�����.
	2. ��� ã��(�Ҹ����)
		ABACABACABA���� ���ڿ��� ���̸� n�̶�� �ϸ�
		k + z[k] = n�� ���� �Ҹ������ ��ġ��.k�� �ε���
*/
