#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

// 1244번 스위치 켜고 끄기
// 분류: 반복문, 구현
// 문제:
//		규칙에 맞게 스위치 끄는 것 구현
// 풀이:
//		문제 상황에 맞게 구현하면 됨
int s[110];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	int p;
	cin >> p;
	while (p--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			for (int i = 1; b * i <= n; i++) {
				s[b * i] = 1 - s[b * i];
			}
		}
		else if (a == 2) {
			s[b] = 1 - s[b];
			int t = 1;
			while (b + t <= n && b - t >= 1 && s[b - t] == s[b + t]) {
				s[b + t] = 1 - s[b + t];
				s[b - t] = 1 - s[b - t];
				t++;
			}				
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << s[i];
		if (i % 20 == 0)
			cout << '\n';
		else
			cout << ' ';
	}
}