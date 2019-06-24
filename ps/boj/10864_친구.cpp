#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 10864번 친구
// 분류: 세기
// 문제:
//		모든 사람의 친구 수를 구하는 문제
// 풀이:
//		a, b가 주어지면 a==b인 경우는 없고 나왔던 a, b도 나오지 않으므로
//		a의 친구 수를 1 증가 시키고 b의 친구 수도 1 증가시킨다.
int friends[1001];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		friends[a]++;
		friends[b]++;
	}
	for (int i = 1; i <= n; i++)
		cout << friends[i] << '\n';
}