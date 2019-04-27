#include <iostream>
#include <string>
#include <queue>
using namespace std;

// n �����
// a ���� ��ġ
// formation �ٸ� ����� �� ������
int n;
int a;
int aState = 0;
int ans = 0; // ��
int formation[100001]; // 0 = Ż��, 1 = POI, 2 = R, 3 = S, 4 = P
string info;

// return l=l�� ����, r=r�� ����, -1=�Ѵ� ����
int loser(int l, int r) {
	// POI�� �ִ� ���
	if (formation[l] == 1) {
		if (aState == 0) {
			if (formation[r] == 2) {
				aState = 4;
			}
			else if (formation[r] == 3) {
				aState = 2;
			}
			else if (formation[r] == 4) {
				aState = 3;
			}
		}
		else {
			if (formation[r] == 2) {
				if (aState != 4) {
					aState = 4;
					ans++;
				}
			}
			else if (formation[r] == 3) {
				if (aState != 2) {
					aState = 2;
					ans++;
				}
			}
			else if (formation[r] == 4) {
				if (aState != 3) {
					aState = 3;
					ans++;
				}
			}
		}
		return r;
	}
	else if (formation[r] == 1) {
		if (aState == 0) { // �ʱ� ������ ���
			if (formation[l] == 2) {
				aState = 4;
			}
			else if (formation[l] == 3) {
				aState = 2;
			}
			else if (formation[l] == 4) {
				aState = 3;
			}
		}
		else {
			if (formation[l] == 2) {
				if (aState != 4) {
					aState = 4;
					ans++;
				}
			}
			else if (formation[l] == 3) {
				if (aState != 2) {
					aState = 2;
					ans++;
				}
			}
			else if (formation[l] == 4) {
				if (aState != 3) {
					aState = 3;
					ans++;
				}
			}
		}
		return l;
	}
	else { // ���� ���
		if (formation[l] == formation[r]) {
			return -1; // �� �� �й�
		}
		else if (formation[l] == 2) {
			if (formation[r] == 3) {
				return r;
			}
			else if (formation[r] == 4) {
				return l;
			}
		}
		else if (formation[l] == 3) {
			if (formation[r] == 2) {
				return l;
			}
			else if (formation[r] == 4) {
				return r;
			}
		}
		else if (formation[l] == 4) {
			if (formation[r] == 2) {
				return r;
			}
			else if (formation[r] == 3) {
				return l;
			}
		}
	}
	return -1;
}

int main(void) {
	cin >> n;
	cin >> a;
	cin >> info;

	// ������ �̿��� �Է��ϴµ�
	// stirng�� index�� formation�� index�� �ٸ��Ƿ� �ٸ��� �����Ѵ�.
	int stringIndex = 0;
	for (int i = 0; i < n; i++) {
		if (i == a) { // POI
			formation[i] = 1;
		}
		else {
			if (info[stringIndex] == 'R') {
				formation[i] = 2;
				stringIndex++;
			}
			else if (info[stringIndex] == 'S') {
				formation[i] = 3;
				stringIndex++;
			}
			else if (info[stringIndex] == 'P') {
				formation[i] = 4;
				stringIndex++;
			}
		}
	}

	while (true) {
		queue<int> round;
		for (int i = 0; i < n; i++)
			if (formation[i] != 0)
				round.push(i);

		if (round.size() == 1)
			break;

		// round���� 2�� ������ ���ڴ� 0���� �ٲ�
		// left, right�� index ��
		while (!round.empty()) {

			// ������ 1�� �̻��� �����Ƿ� �ϳ��� ������
			int left = round.front();
			round.pop();
			// ��������� ������
			if (round.empty()) {
				break;
			}
			// �ƴϸ� ���� ���
			int right = round.front();
			round.pop();

			// �� ����� �ε��� ������
			int loserIndex = loser(left, right);
			if (loserIndex == -1) {
				formation[left] = 0;
				formation[right] = 0;
			}
			else {
				formation[loserIndex] = 0;
			}
		}
	}

	cout << ans << endl;
	return 0;
}