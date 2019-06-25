#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 14264번 정육각형과 삼각형
// 분류: 수학
// 문제:
//		정육각형에 대각선 3개 그어 나온 제일 작은 삼각형의 넓이 구하기
// 풀이:
//		무조건 길이 L인 정삼각형 크기의 삼각형이 가장 작으므로
//		정삼각형 넓이 공식인 (루트(3)/4)*(변*변) 으로 구한다.
int main() {
	int l;
	cout << fixed;
	cout.precision(15);
	
	cin >> l;
	cout << sqrt(3) / 4 * double(l) * double(l) << '\n';
}