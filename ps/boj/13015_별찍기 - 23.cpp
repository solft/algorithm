#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 13015번 별찍기-23
// 분류: 별찍기, 규칙 찾기
// 문제:
//		X 모양 별찍기
// 풀이:
//		부위별로 나눠서 출력한다.찌
int main() {
	int n;
	cin >> n;
	// 윗부분
	for (int i = 0; i < n; i++)
		cout << '*';
	for (int i = 0; i < (n - 2) * 2 + 1; i++)
		cout << ' ';
	for (int i = 0; i < n; i++)
		cout << '*';
	cout << '\n';

	for (int i = 1; i <= n - 2; i++) {
		for (int j = 0; j < i; j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++)
			cout << ' ';
		cout << '*';
		for (int j = (n-2-i)*2+1; j > 0; j--)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++)
			cout << ' ';
		cout << '*';
		cout << '\n';
	}

	// 중간 부분
	for (int i = 0; i < n - 1; i++)
		cout << ' ';
	cout << '*';
	for (int i = 0; i < n - 2; i++)
		cout << ' ';
	cout << '*';
	for (int i = 0; i < n - 2; i++)
		cout << ' ';
	cout << '*';
	cout << '\n';


	// 아랫 부분
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 0; j < n - 1 - i; j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < (i-1)*2+1; j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; j++)
			cout << ' ';
		cout << '*';
		cout << '\n';
	}

	for (int i = 0; i < n; i++)
		cout << '*';
	for (int i = 0; i < (n - 2) * 2 + 1; i++)
		cout << ' ';
	for (int i = 0; i < n; i++)
		cout << '*';
	cout << '\n';
}