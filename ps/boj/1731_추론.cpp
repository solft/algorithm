#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

// 1731번 추론
// 분류: 수학
// 문제:
//		입력받은 수열이 등차인지 등비인지 알아 맞추고 다음 항을 구하는 문제
// 풀이:
//		두 숫자 사이의 관계를 2개 비교해서 등차 or 등비를 알아내고
//		마지막항에 적절한 연산을 해준다.
int num[55];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	
	bool isMultiple = false;
	int next = 0;

	if (num[1] - num[0] == num[n - 1] - num[n - 2]) { // 등차
		next = num[1] - num[0];
	}
	else if (num[1] / num[0] == num[n - 1] / num[n - 2]) { // 등비
		isMultiple = true;
		next = num[1] / num[0];
	}

	if (isMultiple)
		cout << next * num[n - 1] << '\n';
	else
		cout << next + num[n - 1] << '\n';
}