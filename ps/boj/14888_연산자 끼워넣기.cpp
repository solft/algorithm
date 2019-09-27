#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// 14888번 연산자 끼워넣기
// 분류: 브루트 포스
// 문제: 
//		연산자를 아무 순서로 배치할 때
//		나올 수 있는 결과의 최대, 최소 구하기
// 풀이:
//		가능한 모든 연산을 해서 최댓값과 최솟값을
//		업데이트 한다.
int n;
vector<int> numbers;
vector<int> operators(4);
int maxSolution = -2000000000;
int minSolution = 2000000000;

void calculate(int now, int opsCounting) {

	if (opsCounting == 0) {
		if (maxSolution < now)
			maxSolution = now;
		if (minSolution > now)
			minSolution = now;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operators[i] >= 1) {
			if (i == 0) {
				operators[i]--;
				calculate(now + numbers[n - opsCounting], opsCounting - 1);
				operators[i]++;
			}
			else if (i == 1) {
				operators[i]--;
				calculate(now - numbers[n - opsCounting], opsCounting - 1);
				operators[i]++;
			}
			else if (i == 2) {
				operators[i]--;
				calculate(now * numbers[n - opsCounting], opsCounting - 1);
				operators[i]++;
			}
			else if (i == 3) {
				operators[i]--;
				calculate(now / numbers[n - opsCounting], opsCounting - 1);
				operators[i]++;
			}
		}
	}
}

int main() {
	cin >> n;
	numbers.resize(n);
	int initialOps = 0;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
		initialOps += operators[i];
	}
		
	calculate(numbers[0], initialOps);

	cout << maxSolution << '\n' << minSolution << '\n';
}