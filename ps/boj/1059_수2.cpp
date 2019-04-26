#include <iostream>
#include <algorithm>
using namespace std;

// 1059 수2
//	문제: 
//		Lucky Set -> 정수 집합
//		구간 [A, B] -> A <= 정수 <= B, A, B는 양수
//		구간 [A, B]가 Unlucky가 되려면 구간 속의 
//		모든 정수가 Lucky Set에 없어야함
//		Lucky Set과 N이 주어질 때, N을 포함하는 Unlucky 구간의 개수 구하기
//	입력: 
//		L -> Lucky Set의 개수(50이하)
//		Lucky Set -> 1000이하의 중복되지 않는 자연수 집합
//		N -> Lucky Set에서 가장 큰 수보다 작거나 같은 자연수
//	풀이:
//		Lucky Set을 정렬하고 N이 어느 위치에 있는지 알아낸다
//		3가지 경우가 나오는데
//		1) N이 Lucky Set의 수와 같은 경우
//		2) Lucky Set의 두 숫자 사이에 있는 경우
//		3) Lucky Set의 가장 작은 숫자보다 작은 경우
//		각각의 경우 만들 수 있는 경우의 수를 생각해보면
//		1) 0
//		2) (N-num[index])*(num[index+1]-N)-1
//		3) N*(num[0]-N)-1
//		케이스따라 나눠서 계산해주면 된다.
int main() {
	int L;
	int num[55];
	int N;

	cin >> L;
	for (int i = 0; i < L; i++)
		cin >> num[i];
	cin >> N;
	sort(num, num + L);

	int index = -1;
	bool impossible = false;
	for (int i = L - 1; i >= 0; i--) {
		if (N > num[i]) {
			index = i;
			break;
		}
		if (N == num[i]) {
			impossible = true;
			break;
		}
	}

	// N == num[index] => Unlucky 만들기 불가능
	// num[index] < N < num[index+1] => (N-num[index])*(num[index+1]-N)-1
	// N < num[0] => N*(num[0]-N)-1
	if (impossible) {
		cout << 0 << endl;
	}
	else if(index == -1) {
		cout << N * (num[0] - N) - 1 << endl;
	}
	else {
		cout << (N - num[index])*(num[index + 1] - N) - 1 << endl;
	}
}