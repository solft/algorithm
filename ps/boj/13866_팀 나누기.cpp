#include <iostream>
#include <algorithm>
using namespace std;

// 13866번 팀나누기
// 분류: 정렬
// 문제:
//		숫자 4개를 둘 씩 짝지어 더하고 그 차의 최솟값을 구하는 문제
// 풀이:
//		정렬해서 제일 큰거, 제일 작은거 끼리 짝짓고
//		중간 2개를 짝짓는다.
int main() {
	int num[4];
	for (int i = 0; i < 4; i++)
		cin >> num[i];
	sort(num, num + 4);
	cout << abs(num[3] + num[0] - num[1] - num[2]) << '\n';
}