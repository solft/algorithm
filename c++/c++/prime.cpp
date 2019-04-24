// 소수 관련 C++ 함수
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<10000010> bs; // 10^7까지 소수 여부. bs[i] = 0: i는 0 or 1 or 합성수, bs[i] = 1: i는 소수
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
		}
		primes.push_back((int)i); // 소수 목록에 추가.
	}
}

// 소수 판단
bool isPrime(ll N) {
	if (N <= _sieve_size) return bs[N];
	for (int i = 0; i < (int)primes.size(); i++)
		if (N % primes[i] == 0) return false;
	return true;
} // ("primes"에 저장된 마지막 소수)^2 까지 판단 가능


// 소인수 (Prime Factor) 찾기
vi primeFactors(ll N) {
	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N) {
		while (N % PF == 0) {
			N /= PF;
			factors.push_back(PF);
		}
		PF = primes[++PF_idx];
	}
	if (N != 1) factors.push_back(N);
	return factors;
}

// Prime Factor 개수 리턴
ll numPF(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
	while (PF * PF <= N) {
		while (N % PF == 0) {
			N /= PF;
			ans++;
		}
		PF = primes[++PF_idx];
	}
	if (N != 1) ans++;
	return ans;
}