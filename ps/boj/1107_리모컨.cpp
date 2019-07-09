#include <iostream>
#include <queue>

using namespace std;

// 1107�� ������
// �з�: ���Ʈ����
// ����:
//		�����ܿ��� �� ���� ���� ��ȣ�� ���� ���� ��
//		���� ���ڿ� -, +�� ���ϴ� ��ȣ���� �ּ� �� ������ �� �� �ִ��� ���ϴ� ����
// Ǯ��:
//		���� ���̽��� �ִµ� ���ϴ� ä���� 100�� ���(�ȿ������� ��)
//		ó������ -, +�� ã�ư��� ���
//		���峪�� �ʾҴٴ� �����Ͽ� ��ȣ�� �ٷ� ���� ���
//		���峪�� ���� ���� ������ ��ȣ ���� �� -, +�� ã�ư��� ���
//		����� ����ؼ� �ᱹ�� �� ��ȣ�� ���̰ų� �÷�����(���̴°� ���� Ȯ���ؾߵ�)
//		�ش� ��ȣ�� ã���� �ּ� ���� Ƚ���� ���� �� �ְ� �ȴ�.
int now = 100;
int n, m;
int breakdown[10];

// -1 �ٷ� ���� ����, result�� ������ ��
int isPush(int channel) {
	if (channel < 0)
		return -1;
	int result = 0;
	do {
		if (breakdown[channel % 10])
			return -1;
		channel /= 10;
		result++;
	} while (channel != 0);
	return result;
}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int breakNum;
		cin >> breakNum;
		breakdown[breakNum] = 1;
	}

	// -,+ �θ� �̵� ��
	int onlyMinusPlus = abs(n - now);

	// �ش� ���� �ٷΰ���
	int direct = isPush(n);

	if (n == now)
		cout << 0 << '\n';
	else if (direct >= 0) {
		if (onlyMinusPlus < direct)
			cout << onlyMinusPlus << '\n';
		else
			cout << direct << '\n';
	}
	else {
		int pushPlus = n;
		int pushMinus = n;
		bool noAns = true;

		for (int i = 1; i <= onlyMinusPlus; i++) {
			int isPushPlus = isPush(pushPlus + i);
			int isPushMinus = isPush(pushMinus - i);

			if (isPushMinus >= 0) {
				if (isPushMinus + i < onlyMinusPlus)
					cout << isPushMinus + i << '\n';
				else
					cout << onlyMinusPlus << '\n';
				noAns = false;
				break;
			}

			if (isPushPlus >= 0) {
				if (isPushPlus + i < onlyMinusPlus)
					cout << isPushPlus + i << '\n';
				else
					cout << onlyMinusPlus << '\n';
				noAns = false;
				break;
			}
		}

		if (noAns)
			cout << onlyMinusPlus << '\n';
	}
}