#include <iostream>
#include <algorithm>

using namespace std;

// 6443번 애너그램
// 분류: 순열
// 문제:
//		입력 받은 문자열의 애너그램을 출력하는 문제
// 풀이:
//		next_permutation을 이용하여 쉽게 풀었다.
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		
		do {
			cout << str << '\n';
		} while (next_permutation(str.begin(), str.end()));
	}
}