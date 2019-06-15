#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 15921�� ������ �������̾�!!
// �з�: ����
// ����:
//		��հ� ����� ���ϴ� ����
// Ǯ��:
//		double���� �����ϰ� (�����ų� �ݿø���) ����ϸ� �ȴ�.
int record[101];
int n;

int main() {
	cout << fixed;
	cout.precision(2);
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> record[i];
		sum += record[i];
	}
	if (n == 0) {
		cout << "divide by zero\n";
		return 0;
	}
	double mean = double(sum) / double(n);
	double p = 0.0;
	for (int i = 0; i < n; i++)
		p += record[i] * (1 / double(n));
	
	cout << (mean / p) + 0.0001 << '\n';
	
}