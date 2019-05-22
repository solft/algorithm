#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 17203�� ��|��EasyMAX|
// Ǯ��: ����
// ����: 
//		������ �־����� �� �������� 1ĭ ��ȭ���� ���� ���ϴ� ����
// Ǯ��:
//		1ĭ ��ȭ���� �����صΰ� �Է� ������ �� �������� ���Ѵ�.
int song[1010];
int diff[1010];

int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> song[i];
	for (int i = 1; i < n; i++)
		diff[i] = abs(song[i] - song[i - 1]);

	while (q--) {
		int a, b;
		cin >> a >> b;
		int ans = 0;

		for (int i = a; i < b; i++)
			ans += diff[i];
		cout << ans << '\n';
	}
}