#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// 14012번 Large PhD Restaurant
// 분류: 정렬
// 문제:
//		조건에서 가능한 최댓값을 구하기
// 풀이:
//		정렬을 하고나서 가능한것들 다 얻어서 최댓값을 구한다.
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
