#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

// 16503�� ��ȣ ���� ��Ģ����
// �з�: ����
// ����:
//		������ ������ �־����� �� ���� ����Ҷ��� �ڸ��� ����Ҷ� ����߿�
//		������ ���� ����ϰ� ū�� �ڿ� ����ϴ� ����
// Ǯ��:
//		�� �� ����ؼ� ���� �� ���� ����ϰ� ū �� ���߿� ����Ѵ�.
int calculate(int a, int b, char o) {
	if (o == '+') {
		return a + b;
	}
	else if (o == '*') {
		return a * b;
	}
	else if (o == '/') {
		return a / b;
	}
	else if (o == '-') {
		return a - b;
	}
}

int main() {
	int a, b, c;
	char o1, o2;
	cin >> a >> o1 >> b >> o2 >> c;
	int ans1 = calculate(a, b, o1);
	ans1 = calculate(ans1, c, o2);
	int ans2 = calculate(b, c, o2);
	ans2 = calculate(a, ans2, o1);
	if (ans1 > ans2)
		cout << ans2 << '\n' << ans1 << '\n';
	else
		cout << ans1 << '\n' << ans2 << '\n';
}