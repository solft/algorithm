#include <iostream>
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
			primes.push_back((int)i); // 소수 목록에 추가.
		}
	}
}

// 11502번 세 개의 소수문제
// 풀이:
//		소수를 구해서 가능한지 따져보는 문제
//		경우의 케이스가 작아서 브루트포스로 가능한거 다 다져보고
//		결과를 출력했다.
int main() {
	sieve(1000);
	int t;
	scanf("%d", &t);
	while (t--) {
		bool isAns = false;
		int k;
		scanf("%d", &k);
		for (int i = 0; primes[i] < k; i++) {
			for (int j = 0; primes[i] + primes[j] < k; j++) {
				for (int l = 0; primes[i] + primes[j] + primes[l] <= k; l++) {
					if (primes[i] + primes[j] + primes[l] == k) {
						printf("%d %d %d\n", primes[i], primes[j], primes[l]);
						isAns = true;
						break;
					}
				}
				if (isAns)
					break;
			}
			if (isAns)
				break;
		}
		if (isAns)
			continue;
		printf("0\n");
	}
}