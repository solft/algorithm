#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

// 16504�� ��������
// �з�: ����
// ����:
//		�迭�� ���ڰ� �־����� ��Ȯ�� ������ ������ ���� �� ���η�, ���η�
//		��� ��ġ�� �κ� ���ϰ� �̸� �� �� ���� �� ���� �ݺ� �� ����� ���
// Ǯ��:
//		���γ� ���ΰ� ¦���� �� ������ ��� �����ְ� �̸� ������ ������ ���� ���Ѵ�.
typedef long long ll;
ll a[1024][1024];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	int ga = n;
	int se = n;

	while (ga % 2 == 0 && se % 2 == 0) {
		if (ga % 2 == 0) {
			ga /= 2;
			for (int i = 0; i < se; i++)
				for (int j = 0; j < ga; j++)
					a[i][j] += a[i][ga * 2 - j - 1];
		}

		if (se % 2 == 0) {
			se /= 2;
			for (int i = 0; i < ga; i++)
				for (int j = 0; j < se; j++)
					a[j][i] += a[se * 2 - j - 1][i];
		}
	}

	for (int i = 0; i < se; i++) {
		for (int j = 0; j < ga; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}