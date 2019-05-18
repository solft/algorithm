#include <iostream>
#include <algorithm>
#include <vector>

// 15649�� N�� M(1)
// �з�: ���
// ����:
//		n�� m�� �Է����� ������
//		1���� n���� �� �߿� m���� �����ϴ� ����� ���� ����ϴ� ����
// Ǯ��:
//		��͸� �̿��Ͽ�
//		1~n �߿� ������ �����ٰ� ����� m�� �Ǹ� ����ϰ� �׸��д�.
using namespace std;
int n, m;
vector<int> subset;
int chosen[10];
void search() {
	if (subset.size() == m) {
		for (int s : subset)
			cout << s << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (chosen[i]) continue;
			chosen[i] = true;
			subset.push_back(i);
			search();
			chosen[i] = false;
			subset.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;
	search();
}
