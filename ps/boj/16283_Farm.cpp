#include <iostream>
#include <cmath>

using namespace std;

// 16283번 Farm
// 분류: 조건문
// 문제:
//		2차방정식 풀기
// 풀이:
//		여러 조건을 따져가며 케이스를 잘 나눠야한다.
//		답이 있는 경우, 없는 경우, 여러개인 경우
int main() {
	int a, b, n, w;
	cin >> a >> b >> n >> w;
	if (a == b) {
		if (w % a == 0) {
			if (w / a == n) {
				if (n == 2)
					cout << 1 << ' ' << 1 << '\n';
				else
					cout << -1 << '\n';
			}
			else
				cout << -1 << '\n';
		}
		else
			cout << -1 << '\n';
	}
	else if ((w - b * n) % (a - b) != 0 || (w - a * n) % (b - a) != 0)
		cout << -1 << '\n';
	else {
		int sheep = (w - b * n) / (a - b);
		int goat = (w - a * n) / (b - a);
		if (sheep <= 0 || goat <= 0)
			cout << -1 << '\n';
		else
			cout << sheep << ' ' << goat << '\n';
	}
}