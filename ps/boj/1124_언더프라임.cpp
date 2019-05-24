#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

// 1124번 언더프라임
// 분류: 소수
// 문제:
//		숫자 범위에서 소인수분해한 소수 개수가 소수개인 것의 개수 구하기
// 풀이:
//		소수 구해두고 소수를 이용해 소인수 구한 뒤 게스 체크한다.
typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<100010> bs; // 10^7까지 소수 여부. bs[i] = 0: i는 0 or 1 or 합성수, bs[i] = 1: i는 소수
vi primes; // 찾은 소수 목록

// [0, upperbound] 범위의 소수 생성
void sieve(ll upperbound) {
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) {
		if (bs[i]) { // i가 소수라면 _sieve_size 이하의 i 배수는 모두 합성수
			for (ll j = i * i; j <= _sieve_size; j += i)
				bs[j] = 0;
			primes.push_back((int)i); // 소수 목록에 추가.
		}
	}
}

// 소수 판단
bool isPrime(ll N) {
	if (N <= _sieve_size) return bs[N];
	for (int i = 0; i < (int)primes.size(); i++)
		if (N % primes[i] == 0) return false;
	return true;
} // ("primes"에 저장된 마지막 소수)^2 까지 판단 가능

int main() {
	sieve(100000);

	int a, b;
	cin >> a >> b;
	int ans = 0;

	for (int i = a; i <= b; i++) {
		int c = 0;

		int temp = i;
		int index = 0;
		while (temp > 1) {
			if (temp % primes[index] == 0) {
				c++;
				temp /= primes[index];
			}
			else {
				index++;
			}
		}

		if (isPrime(c))
			ans++;
	}
	cout << ans << '\n';
}