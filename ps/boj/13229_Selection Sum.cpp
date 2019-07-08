#include <iostream>
#include <cmath>

using namespace std;

// 13229번 Selection Sum
// 분류: 합배열
// 문제:
//		인덱스 start ~ end 까지의 합 구하기
// 풀이:
//		누적합 배열을 만들어서 [end] - [start-1]로 구간합을 빠르게 구한다.
int n, m, s, e;
int num[100001];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		num[i] += num[i - 1];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << (num[e+1] - num[s]) << '\n';
	}
}