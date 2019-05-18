#include <iostream>
#include <algorithm>
#include <vector>

// 15649번 N과 M(1)
// 분류: 재귀
// 문제:
//		n과 m이 입력으로 들어오기
//		1부터 n까지 수 중에 m개를 선택하는 경우의 수를 출력하는 문제
// 풀이:
//		재귀를 이용하여
//		1~n 중에 선택해 나가다가 사이즈가 m이 되면 출력하고 그만둔다.
using namespace std;
int n, m;
vector<int> subset;
int chosen[10];
void search() {
	if (subset.size() == m) {
		for (int s : subset)
			cout << s << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (chosen[i]) continue;
			chosen[i] = true;
			subset.push_back(i);
			search();
			chosen[i] = false;
			subset.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;
	search();
}
