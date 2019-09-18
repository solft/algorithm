#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 15353번 큰 수 A+B (2)
// 분류: 구현
// 문제:
//		엄청 큰 수의 덧셈을 구현하는 문제
// 풀이:
//		배열에 수를 저장해서 자릿수 올라가는 부분 구현해주면 된다.
int A[10010];
int B[10010];

int main() {
	string a, b;
	cin >> a >> b;

	int longLength = max(a.length(), b.length());
	int lastIndex = longLength;

	for (unsigned int i = 0; i < a.length(); i++)
		A[i] = a[a.length() - i - 1] - '0';
	for (unsigned int i = 0; i < b.length(); i++)
		B[i] = b[b.length() - i - 1] - '0';

	for (int i = 0; i < longLength; i++) {
		A[i] = A[i] + B[i];
		if (A[i] >= 10) {
			A[i + 1] += 1;
			A[i] %= 10;

			if (i == longLength - 1)
				lastIndex++;
		}
	}

	string ans = "";
	for (int i = 0; i < lastIndex; i++) {
		ans += char(A[lastIndex - i - 1] + '0');
	}
	cout << ans << '\n';
}