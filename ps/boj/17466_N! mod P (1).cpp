#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// 17466�� N! mod P (1)
// �з�: ����
// ����:
//		N! mod P�� ���ϴ� ����
// Ǯ��:
//		����ؼ� ���Ѵ�.
//		���� Ǯ�̴� ã�� ���ߴ�.
int main() {
	long long n, p;
	cin >> n >> p;

	long long sol = 1;
	for (int i = n; i > 1; i--) {
		sol *= i;
		sol %= p;
	}

	cout << sol << '\n';
}