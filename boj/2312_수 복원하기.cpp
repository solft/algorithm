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
		}
		primes.push_back((int)i); // 소수 목록에 추가.
	}
}

// 2312번 수 복원하기
// 문제: 
//		양의 정수 N을 소인수분해한 결과를 출력하는 문제이다.
//		소수를 이용해 푼다.
// 풀이:
//		소인수의 개수까지 구해야 하므로 소수를 구해두고
//		나눠가며 소인수면 카운트를 증가시켜가며 진행했다.
//		인덱스가 뭘 의미하는지 인덱스의 범위를 어디가지 
//		두어야 할 지 주의하면된다.
vector<int> ans;

int main() {
	// 100000 이하의 소수 목록 생성
	sieve(100000);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		ans.assign(n+1, 0);
		int index = 0;
		while (n > 1) {
			if (n % primes[index] == 0) {
				ans[primes[index]]++;
				n /= primes[index];
			}
			else {
				index++;
			}
		}

		for (int i = 0; i <= index; i++) {
			if(ans[primes[i]]>0)
				cout << primes[i] << " " << ans[primes[i]] << endl;
		}
	}
}