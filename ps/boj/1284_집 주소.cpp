#include <iostream>
#include <stack>
using namespace std;


// 1284�� �� �ּ�
// �з�: ���� ����
// ����:
//		1�̸� 3 ���ϰ�, 0�̸� 5 ���ϰ� �������� 4 ���ϴ� ����
// Ǯ��:
//		�ڸ��� �ϳ��� ���� Ȯ���Ѵ�.
int solution(int num) {
	int result = 1;
	while (num > 0) {
		int now = num % 10;
		num /= 10;

		if (now == 1)
			result += 3;
		else if (now == 0)
			result += 5;
		else
			result += 4;
	}
	return result;
}

int main() {
	int n;
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		cout << solution(n) << '\n';
	}
}