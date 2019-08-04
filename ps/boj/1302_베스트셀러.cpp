#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 1302�� ����Ʈ����
// �з�: ����
// ����:
//		���� ���� ���� ���ڿ� ���
// Ǯ��:
//		�����ؼ� �� �� ī����
int main() {
	vector<string> books;
	int n;
	cin >> n;
	books.resize(n);
	for (int i = 0; i < n; i++)
		cin >> books[i];
	sort(books.begin(), books.end());
	int ansIndex = 0;
	int ans = 1;
	string before = books[0];
	int temp = 1;
	for (int i = 1; i < n; i++) {
		if (before == books[i])
			temp++;
		else {
			if (temp > ans) {
				ans = temp;
				ansIndex = i - 1;
			}
			before = books[i];
			temp = 1;
		}
	}

	if (temp > ans) {
		ans = temp;
		ansIndex = n - 1;
	}
	cout << books[ansIndex] << '\n';
}