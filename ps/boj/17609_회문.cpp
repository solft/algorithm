#include <iostream>
using namespace std;

// 17609번 회문
// 분류: 회문(Palindrome)
// 문제:
//		주어진 문자열이 회문인지 유사회문인지 구하기
// 풀이:
//		회문인 경우 O(n)에 확인 가능
//		유사회문인 경우 모든 문자 하나씩 빼면서 회문 검사하면 시간 초과
//		그래서 회문 처럼 검사하다가 다른 문자가 나오면 
//		왼쪽 문자를 뺄건지 오른쪽 문자를 뺄건지 판단해야 하는데
//		한번은 왼쪽 빼고 한번은 오른쪽 빼서 그 후로 또 빼야하는 경우가
//		생기면 유사회문이 될 수 없고 둘 중 한 가지 경우에서 회문이 되면
//		유사회문으로 판단할 수 있다.

bool isPalindrome(string str) {
	int length = str.length();
	int half = length / 2;

	for (int i = 0; i < half; i++) {
		if (str[i] != str[length - i - 1]) {
			return false;
		}
	}

	return true;
}

bool isPseudoPalindrome(string str) {
	int length = str.length();
	bool leftCheck = true;
	bool rightCheck = true;

	int leftIdx = 0;
	int rightIdx = length - 1;
	bool isDelete = false;

	// 무조건 왼쪽 문자를 빼기
	while (leftIdx < rightIdx) {
		if (str[leftIdx] != str[rightIdx]) {
			if (isDelete) {
				leftCheck = false;
				break;
			}
			else {
				isDelete = true;
				leftIdx++;
				continue;
			}
		}
		else {
			leftIdx++;
			rightIdx--;
		}
	}

	// 초기화
	leftIdx = 0;
	rightIdx = length - 1;
	isDelete = false;

	// 무조건 오른쪽 문자를 빼기
	while (leftIdx < rightIdx) {
		if (str[leftIdx] != str[rightIdx]) {
			if (isDelete) {
				rightCheck = false;
				break;
			}
			else {
				isDelete = true;
				rightIdx--;
				continue;
			}
		}
		else {
			leftIdx++;
			rightIdx--;
		}
	}

	return (leftCheck || rightCheck);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		string str;
		cin >> str;

		if (isPalindrome(str)) {
			cout << 0 << '\n';
		}
		else if (isPseudoPalindrome(str)) {
			cout << 1 << '\n';
		}
		else {
			cout << 2 << '\n';
		}
	}
}