#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

// 5636번 소수 부분 문자열
// 분류: 소수, 문자열
// 문제:
//		주어진 숫자 문자열의 부분 문자열에서 100,000 이하의 소수 중 가장 큰 소수를 찾는 문제
// 풀이:
//		0 때문에 모든 길이의 부분 문자열을 다 따져 주었다.
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

// 소수 판단
bool isPrime(ll N) {
	if (N <= _sieve_size) return bs[N];
	for (int i = 0; i < (int)primes.size(); i++)
		if (N % primes[i] == 0) return false;
	return true;
} // ("primes"에 저장된 마지막 소수)^2 까지 판단 가능

int main() {
	sieve(100000);

	while (1) {
		string str;
		cin >> str;
		if (str == "0")
			break;

		int ans = 0;
		// 길이 1부터 5자리 가지 잘라내기
		for (int i = 5; i >= 1; i--) {

			for (int j = 0; j + i - 1 < str.length(); j++) {
				int temp = stoi(str.substr(j, i));
				if (isPrime(temp))
					if(ans < temp)
						ans = temp;
			}
		}
		cout << ans << '\n';
	}
}
