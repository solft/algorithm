#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 10874번 이교수님의 시험
// 분류: % 연산
// 문제:
//		((j-1) mod 5) + 1 인 것이 몇 개인지 구하는 문제
// 풀이:
//		% 연산을 사용한다.
int main() {
	int n;
	vector<int> ans;
	cin >> n;
	for (int person = 1; person <= n; person++) {
		int score = 0;

		for (int i = 1; i <= 10; i++) {
			int num;
			cin >> num;
			if (((i - 1) % 5) + 1 == num)
				score++;
		}
		if (score == 10)
			ans.push_back(person);
	}

	for (auto p : ans)
		cout << p << '\n';
}