#include <iostream>
using namespace std;

// 14891�� ��Ϲ���
// �з�: ����
// ����:
//		��Ϲ��� ���� ���� �ٸ� ��� ���������� ���ư�����
//		������ �ڿ� Ư�� ��ϸ� �ð�, �ݽð� ��������
//		�� �� ȸ�� ��Ų �� 12�� ���⿡ S���� �� ������ ���ϴ� ����
// Ǯ��:
//		�ٸ� ��Ͽ� �����ϴ� �κи� �ε����� ���� �����ؼ�
//		�� �κг��� ���� ȸ���ϴ� ��ϸ� ���� ��
//		ȸ����Ų��. �׸��� ���������� �ش� �ε������� 
//		12�� ���� ��ġ������ ��� ��ġ�� ã�Ƴ��� 12�� ���� ���Ѵ�.

int checkRange(int num) {
	if (num > 7)
		return 0;
	else if (num < 0)
		return 7;
	else
		return num;
}

int main() {
	char sawtooth[4][9];
	int idxPointer[6];

	for (int i = 0; i < 4; i++)
		cin >> sawtooth[i];

	idxPointer[0] = 2; // 1�� ������
	idxPointer[1] = 6; // 2�� ����
	idxPointer[2] = 2; // 2�� ������
	idxPointer[3] = 6; // 3�� ����
	idxPointer[4] = 2; // 3�� ������
	idxPointer[5] = 6; // 4�� ����

	// ȸ�� Ƚ��
	int k;
	cin >> k;
	while (k--) {
		int position, direction;
		cin >> position >> direction;
		int rotatePos[4] = { 0, 0, 0, 0 };

		if (position == 1) {
			rotatePos[0] = -direction;

			if (sawtooth[0][idxPointer[0]] != sawtooth[1][idxPointer[1]]) {
				rotatePos[1] = direction;

				if (sawtooth[1][idxPointer[2]] != sawtooth[2][idxPointer[3]]) {
					rotatePos[2] = -direction;

					if (sawtooth[2][idxPointer[4]] != sawtooth[3][idxPointer[5]]) {
						rotatePos[3] = direction;
					}
				}
			}
		}
		else if (position == 2) {
			rotatePos[1] = -direction;

			if (sawtooth[0][idxPointer[0]] != sawtooth[1][idxPointer[1]])
				rotatePos[0] = direction;

			if (sawtooth[1][idxPointer[2]] != sawtooth[2][idxPointer[3]]) {
				rotatePos[2] = direction;
				if (sawtooth[2][idxPointer[4]] != sawtooth[3][idxPointer[5]]) {
					rotatePos[3] = -direction;
				}
			}
		}
		else if (position == 3) {
			rotatePos[2] = -direction;

			if (sawtooth[1][idxPointer[2]] != sawtooth[2][idxPointer[3]]) {
				rotatePos[1] = direction;
				if (sawtooth[0][idxPointer[0]] != sawtooth[1][idxPointer[1]]) {
					rotatePos[0] = -direction;
				}
			}
			
			if (sawtooth[2][idxPointer[4]] != sawtooth[3][idxPointer[5]]) {
				rotatePos[3] = direction;
			}
		}
		else if (position == 4) {
			rotatePos[3] = -direction;
			if (sawtooth[2][idxPointer[4]] != sawtooth[3][idxPointer[5]]) {
				rotatePos[2] = direction;
				if (sawtooth[1][idxPointer[2]] != sawtooth[2][idxPointer[3]]) {
					rotatePos[1] = -direction;
					if (sawtooth[0][idxPointer[0]] != sawtooth[1][idxPointer[1]]) {
						rotatePos[0] = direction;
					}
				}
			}
		}

		idxPointer[0] += rotatePos[0];
		idxPointer[1] += rotatePos[1];
		idxPointer[2] += rotatePos[1];
		idxPointer[3] += rotatePos[2];
		idxPointer[4] += rotatePos[2];
		idxPointer[5] += rotatePos[3];

		for (int i = 0; i < 6; i++)
			idxPointer[i] = checkRange(idxPointer[i]);
	}

	int ans = 0;
	ans += (sawtooth[0][(idxPointer[0] + 6) % 8] - '0') * 1;
	ans += (sawtooth[1][(idxPointer[2] + 6) % 8] - '0') * 2;
	ans += (sawtooth[2][(idxPointer[4] + 6) % 8] - '0') * 4;
	ans += (sawtooth[3][(idxPointer[5] + 2) % 8] - '0') * 8;

	cout << ans << '\n';
}