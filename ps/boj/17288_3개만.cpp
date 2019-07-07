#include <iostream>

using namespace std;

// 17288번 3개만!
// 분류: 카운팅
// 문제:
//		숫자가 1씩 증가하는 연속된 정확히 길이 3짜리 숫자 부분이 몇 개 있는지 구하는 문제
// 풀이:
//		숫자가 증가하면 count를 늘려가며 3일 때 끝나면 1 증가시킨다.
//		마지막 부분만 한 번 더 생각해 준다.
int main() {
	string num_str;
	cin >> num_str;

	int before = num_str[0] - '0';
	int count = 1;
	int ans = 0;
	for (unsigned int i = 1; i < num_str.size(); i++) {
		int num = num_str[i] - '0';

		
		if (before + 1 == num) {
			count++;
			before = num;
		}
		else {
			if (count == 3)
				ans++;
			count = 1;
			before = num;
		}
	}

	if (count == 3)
		ans++;

	cout << ans << '\n';
}