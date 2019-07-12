#include <iostream>
using namespace std;

// 2529�� �ε�ȣ
// �з�: �׸���
// ����:
//		�ε�ȣ �迭�� �־����� �ش� �ε�ȣ�� �����ϰ�
//		0 ~ 9���� �� �� �ϳ��� ���� �� ������� ������ �ִ�, �ּ� ���ϱ�
// Ǯ��:
//		���� ���ڴ� ���� ������ ū ���ڴ� ū �� ���� �� ������
//		�ڸ��� ã�� �ڿ� ä��������.
int k;
char sign[11];
int max_ans[11];
int min_ans[11];

int main() {
	cin >> k;
	for (int i = 0; i < k + 1; i++)
		max_ans[i] = min_ans[i] = -1;

	for (int i = 0; i < k; i++)
		cin >> sign[i+1];

	// ���� ����
	for (int i = 0; i < k+1; i++) {
		// �� �ڸ�
		int index = 0;
		while (index < k) {
			if (min_ans[index] == -1) {
				if (sign[index + 1] == '<')
					break;
				else if (sign[index + 1] == '>') {
					if (min_ans[index + 1] == -1)
						index++;
					else
						break;
				}
				else
					index++;
			}
			else
				index++;
		}
		min_ans[index] = i;
	}

	// ���� ����
	for (int i = 0; i < k + 1; i++) {
		int input_number = 9 - i;
		// �� �ڸ�
		int index = 0;
		while (index < k) {
			if (max_ans[index] == -1) {
				if (sign[index + 1] == '>')
					break;
				else if (sign[index + 1] == '<') {
					if (max_ans[index + 1] == -1)
						index++;
					else
						break;
				}
				else
					index++;
			}
			else
				index++;
		}
		max_ans[index] = input_number;
	}

	for (int i = 0; i < k + 1; i++)
		cout << max_ans[i];
	cout << '\n';
	for (int i = 0; i < k+1; i++)
		cout << min_ans[i];
	cout << '\n';
}