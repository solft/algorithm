#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// 14012�� Large PhD Restaurant
// �з�: ����
// ����:
//		���ǿ��� ������ �ִ��� ���ϱ�
// Ǯ��:
//		������ �ϰ��� �����Ѱ͵� �� �� �ִ��� ���Ѵ�.
vector<pair<long long, long long>> a;

int main() {
	long long n, m;
	cin >> n >> m;
	a.resize(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i].first;
	for (int i = 0; i < n; i++)
		cin >> a[i].second;

	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if (a[i].first < a[i].second)
			if (m >= a[i].first)
				m += (a[i].second - a[i].first);
	}
	cout << m << '\n';
}
