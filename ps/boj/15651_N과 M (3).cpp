#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 15651번 N과 M (3)
// 분류: 백트래킹
// 문제:
//		중복을 허용해서 1~N 중 M개의 수를 골라
//		모두 출력하는 문제
//	풀이:
//		선택할 때 처음부터 다 선택하도록 하고
//		종료조건은 M개를 선택했을 때로 한다.
int n, m;
vector<int> ans;

void solution(int count) {

	if (count == m) {
		for (int num : ans)
			printf("%d ", num);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		ans.push_back(i);
		solution(count + 1);
		ans.pop_back();
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		ans = { i };
		solution(1);
	}
}