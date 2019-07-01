#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 10874�� �̱������� ����
// �з�: % ����
// ����:
//		((j-1) mod 5) + 1 �� ���� �� ������ ���ϴ� ����
// Ǯ��:
//		% ������ ����Ѵ�.
int main() {
	int n;
	vector<int> ans;
	cin >> n;
	for (int person = 1; person <= n; person++) {
		int score = 0;

		for (int i = 1; i <= 10; i++) {
			int num;
			cin >> num;
			if (((i - 1) % 5) + 1 == num)
				score++;
		}
		if (score == 10)
			ans.push_back(person);
	}

	for (auto p : ans)
		cout << p << '\n';
}