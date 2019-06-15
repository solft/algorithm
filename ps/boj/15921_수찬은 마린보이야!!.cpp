#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 15921번 수찬은 마린보이야!!
// 분류: 수학
// 문제:
//		평균과 기댓값을 구하는 문제
// 풀이:
//		double형에 주의하고 (나누거나 반올림시) 계산하면 된다.
int record[101];
int n;

int main() {
	cout << fixed;
	cout.precision(2);
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> record[i];
		sum += record[i];
	}
	if (n == 0) {
		cout << "divide by zero\n";
		return 0;
	}
	double mean = double(sum) / double(n);
	double p = 0.0;
	for (int i = 0; i < n; i++)
		p += record[i] * (1 / double(n));
	
	cout << (mean / p) + 0.0001 << '\n';
	
}