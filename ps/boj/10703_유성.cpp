#include <iostream>
using namespace std;
// 10703�� ����
// �з�: ���
// ����:
//		���� ������ �־������� �� ���� �� �ּҰŸ� ã��
// Ǯ��:
//		�ּҰŸ��� ã������ �ϴ� X(����)�� �־���ϰ�
//		�� �������� .�̸� ������Ű�ٰ� �ٽ� X(����)�� ������ .������ 0���� �����ϰ�
//		#(��)�� ������ �����.
//		���� ���� �� ó���� �����༭ �� �� Ʋ�ȴ�.
char photo[3000][3000];
char result[3000][3000];
int r, s;

int main() {
	cin >> r >> s;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < s; j++)
			cin >> photo[i][j];

	int minAir = s + 1;

	for (int j = 0; j < s; j++) {
		int colAir = 0;
		int hasX = false;
		for (int i = 0; i < r; i++) {
			if (photo[i][j] == 'X') {
				hasX = true;
				colAir = 0;
				continue;
			}
			else if (photo[i][j] == '.')
				colAir++;
			else if (photo[i][j] == '#')
				break;
		}
//		cout << "colAir = " << colAir << endl;
		if (hasX && minAir > colAir)
			minAir = colAir;
	}

//	printf("Input TEST: \n");
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < s; j++) {
//			cout << photo[i][j];
//		}
//		cout << '\n';
//	}
//	cout << minAir << endl;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			if (photo[i][j] == 'X')
				result[i + minAir][j] = 'X';
			else if (photo[i][j] == '#')
				result[i][j] = '#';
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			if (result[i][j] == 0)
				cout << '.';
			else
				cout << result[i][j];
		}
		cout << '\n';
	}
}