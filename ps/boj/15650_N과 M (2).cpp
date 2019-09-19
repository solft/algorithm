#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 15650번 N과 M (2)
// 분류: 백트래킹
// 문제:
//		1~N 중 M개를 선택해 오름차순 수열을 출력하는 문제
// 풀이:
//		N개 중 M개를 선택하는데 선택한 것은 체크를 해두고
//		다음번 선택은 현재 제일 큰거보다 큰 수부터 고른다.
//		계속 고르다가 M개를 고르면 현재 수를 출력한다.
int n, m;
vector<int> ans;
int selected[10];

void solution(int count) {

	if (count == m) {
		for (int num : ans)
			cout << num << " ";
		cout << '\n';
	}

	for (int i = ans.back() + 1; i <= n; i++) {
		if (selected[i] == 0) {
			ans.push_back(i);
			selected[i] = 1;
			solution(count + 1);
			selected[i] = 0;
			ans.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		ans = { i };
		solution(1);
	}
}