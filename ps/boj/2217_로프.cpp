#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

// 2217�� ����
// �з�: �ִ� ��Ģ ã��
// ����:
//		�ּڰ� * ������ �ִ� ���ϱ�
// Ǯ��:
//		������ �ϰ� �ϳ��� �÷������� �ּ� * ������ �ִ븦 ã�´�
vector<int> rope;
int n;

int main() {
	cin >> n;
	rope.resize(n);
	for (int i = 0; i < n; i++)
		cin >> rope[i];
	sort(rope.begin(), rope.end());

	int ans = 0;
	int count = 0;
	for (int i = n - 1; i >= 0; i--) {
		count++;
		if (ans <= rope[i] * count) {
			ans = rope[i] * count;
		}
	}

	cout << ans << '\n';
}
