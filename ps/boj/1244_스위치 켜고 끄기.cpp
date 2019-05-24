#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

// 1244�� ����ġ �Ѱ� ����
// �з�: �ݺ���, ����
// ����:
//		��Ģ�� �°� ����ġ ���� �� ����
// Ǯ��:
//		���� ��Ȳ�� �°� �����ϸ� ��
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