#include <iostream>
using namespace std;
// 16546�� Missing Runners
// ����:
//		1~N ���� ���� �Է¹ް�
//		�ȳ��� ���� ã��
// Ǯ��:
//		�Է¹����� üũ�ϰ�
//		�Է¾ȹ����� ����Ѵ�.
bool runner[35000];

int main() {
	int n;
	cin >> n;
	int r;
	for (int i = 0; i < n - 1; i++) {
		cin >> r;
		runner[r] = true;
	}
	for(int i=1; i<=n; i++)
		if (!runner[i]) {
			cout << i << endl;
			break;
		}
}