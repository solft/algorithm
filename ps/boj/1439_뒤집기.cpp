#include <iostream>
#include <vector>

using namespace std;

// 1439번 뒤집기
// 분류: 변화점 카운팅
// 문제:
//		연속된 같은 수를 뒤집어서 모든 수를 같게 만들기 위해 뒤집는 횟수 구하는 문제
// 풀이:
//		연속된 0과 1의 개수를 카운팅 한 뒤 작은 수 만큼 뒤집기 연산을 하면 된다.
char s[1000001];

int main() {

	cin >> s;
	int counter[2] = { 0, 0 };

	char before = s[0];
	for (int i = 1; s[i] != '\0'; i++) {
		if (before != s[i]) {
			counter[before - '0']++;
			before = s[i];
		}
	}
	counter[before - '0']++;

	if (counter[0] < counter[1])
		cout << counter[0] << '\n';
	else
		cout << counter[1] << '\n';

}