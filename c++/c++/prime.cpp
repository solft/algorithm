// �Ҽ� ���� C++ �Լ�
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<10000010> bs; // 10^7���� �Ҽ� ����. bs[i] = 0: i�� 0 or 1 or �ռ���, bs[i] = 1: i�� �Ҽ�
vi primes; // ã�� �Ҽ� ���

// [0, upperbound] ������ �Ҽ� ����
void sieve(ll upperbound) {
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) {
		if (bs[i]) { // i�� �Ҽ���� _sieve_size ������ i ����� ��� �ռ���
			for (ll j = i * i; j <= _sieve_size; j += i)
				bs[j] = 0;
		}
		primes.push_back((int)i); // �Ҽ� ��Ͽ� �߰�.
	}
}

// �Ҽ� �Ǵ�
bool isPrime(ll N) {
	if (N <= _sieve_size) return bs[N];
	for (int i = 0; i < (int)primes.size(); i++)
		if (N % primes[i] == 0) return false;
	return true;
} // ("primes"�� ����� ������ �Ҽ�)^2 ���� �Ǵ� ����


// ���μ� (Prime Factor) ã��
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

// Prime Factor ���� ����
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