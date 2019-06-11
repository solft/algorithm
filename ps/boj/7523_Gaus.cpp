#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 7523번 Gaus
// 분류: 수학
// 문제:
//		n부터 m까지 수들의 합 구하기
// 풀이:
//		n~m 합 = ((n+m)*(m-n+1))/2
typedef long long ll;

int main() {
	int t;
	cin >> t;
	for(int i=1; i<=t; i++){
		ll n, m;
		cin >> n >> m;
		cout <<"Scenario #"<< i<<":\n" << (n + m) * (m - n + 1) / 2 << "\n\n";
	}
}