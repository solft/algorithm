#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 2991번 사나운 개
// 분류: 구현
// 문제:
//		개가 사나운 텀이 주어질때 
//		해당 시간에 몇마리가 사나운지 출력
// 풀이:
//		최대시간이 999이므로 개가 사나울 때의 시간에 1을 더해주었다.
int dog[1000];

int main() {
	int a, b, c, d;
	int p, m, n;
	cin >> a >> b >> c >> d;
	cin >> p >> m >> n;

	int index = 1;
	while (true) {
		for (int i = 0; i < a; i++)
			dog[index++]++;
		for (int i = 0; i < b; i++)
			index++;
		if (index > 1000)
			break;
	}
	index = 1;
	while (true) {
		for (int i = 0; i < c; i++)
			dog[index++]++;
		for (int i = 0; i < d; i++)
			index++;
		if (index > 1000)
			break;
	}

	cout << dog[p] << '\n';
	cout << dog[m] << '\n';
	cout << dog[n] << '\n';
}
