#include <iostream>
using namespace std;

// 17609�� ȸ��
// �з�: ȸ��(Palindrome)
// ����:
//		�־��� ���ڿ��� ȸ������ ����ȸ������ ���ϱ�
// Ǯ��:
//		ȸ���� ��� O(n)�� Ȯ�� ����
//		����ȸ���� ��� ��� ���� �ϳ��� ���鼭 ȸ�� �˻��ϸ� �ð� �ʰ�
//		�׷��� ȸ�� ó�� �˻��ϴٰ� �ٸ� ���ڰ� ������ 
//		���� ���ڸ� ������ ������ ���ڸ� ������ �Ǵ��ؾ� �ϴµ�
//		�ѹ��� ���� ���� �ѹ��� ������ ���� �� �ķ� �� �����ϴ� ��찡
//		����� ����ȸ���� �� �� ���� �� �� �� ���� ��쿡�� ȸ���� �Ǹ�
//		����ȸ������ �Ǵ��� �� �ִ�.

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

	// ������ ���� ���ڸ� ����
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

	// �ʱ�ȭ
	leftIdx = 0;
	rightIdx = length - 1;
	isDelete = false;

	// ������ ������ ���ڸ� ����
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