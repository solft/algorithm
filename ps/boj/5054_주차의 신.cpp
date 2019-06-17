#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 5054�� ������ ��
// �з�: �ִ� �ּڰ�
// ����:
//		������ �� ��ǥ�� ������ �־����� ��� ��ǥ�� �Դٰ����ϴ� �ּڰ��� ���ϴ� ����
// Ǯ��:
//		2 * (�ִ� - �ּڰ�)
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n; 
		cin >> n;
		vector<int> store;
		store.resize(n);
		int min_pos = 1000000000;
		int max_pos = 0;
		for (int i = 0; i < n; i++) {
			cin >> store[i];
			if (min_pos > store[i])
				min_pos = store[i];
			if (max_pos < store[i])
				max_pos = store[i];
		}

		cout << 2 * (max_pos - min_pos) << '\n';
	}
}