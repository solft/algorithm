#include <iostream>
using namespace std;

// 1592번 영식이와 친구들
// 풀이:
//		조건에 따라 뒤로 보내고 앞으로 보내서
//		원순열처럼 계산하면 된다.
//		반복문 순서는
//		1. 공을 받는다 (F[ball] 1증가)
//		2. 조건 검사(m번 이상 받았는지?)
//		3. 던진다
//		4. 다음 받을 사람 정하기
int main() {
	int n, m, l;
	cin >> n >> m >> l;

	int F[1001] = { 0, };

	int ball = 0;
	int ans = 0;
	while (true) {
		F[ball]++;
		if (F[ball] >= m)
			break;
		ans++;

		if (F[ball] % 2 == 1) {	
			ball += l;
			ball %= n;
		}
		else {
			ball += n;
			ball -= l;
			ball %= n;
		}
	}
	cout << ans << endl;
}