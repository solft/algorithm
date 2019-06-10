#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 17269번 이름궁합 테스트
// 분류: 문자열 번갈아 처리하기
// 문제:
//		두 문자열을 입력 받고 번갈아가며 어떤 문자인지 확인 후
//		둘의 획수 합을 계속 계산해 나가며 마지막 남은 2개를 출력하는 문제
// 풀이:
//		두 문자열을 합쳐서 만든 획수 배열을 만들어
//		두 숫자만 남을 때까지 더해준다.
int result[220];

int main() {
	int alpha[26] = { 3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1 };
	int n, m;
	string a, b;
	cin >> n >> m;
	cin >> a >> b;


	int idx_a = 0;
	int idx_b = 0;
	for (int i = 0; i < m + n; i++) {
		if (idx_a >= n) {
			result[i] = alpha[b[idx_b] - 'A'];
			idx_b++;
		}
		else if (idx_b >= m) {
			result[i] = alpha[a[idx_a] - 'A'];
			idx_a++;
		}
		else {
			if (i % 2 == 0) {
				result[i] = alpha[a[idx_a] - 'A'];
				idx_a++;
			}
			else {
				result[i] = alpha[b[idx_b] - 'A'];
				idx_b++;
			}
		}
	}

	for (int i = m + n - 2; i > 0; i--)
		for (int j = 0; j <= i; j++)
			result[j] = (result[j] + result[j + 1]) % 10;

	cout << result[0] * 10 + result[1] << "%\n";
}
