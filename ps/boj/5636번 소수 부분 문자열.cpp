#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

// 5636�� �Ҽ� �κ� ���ڿ�
// �з�: �Ҽ�, ���ڿ�
// ����:
//		�־��� ���� ���ڿ��� �κ� ���ڿ����� 100,000 ������ �Ҽ� �� ���� ū �Ҽ��� ã�� ����
// Ǯ��:
//		0 ������ ��� ������ �κ� ���ڿ��� �� ���� �־���.
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
			primes.push_back((int)i); // �Ҽ� ��Ͽ� �߰�.
		}
	}
}

// �Ҽ� �Ǵ�
bool isPrime(ll N) {
	if (N <= _sieve_size) return bs[N];
	for (int i = 0; i < (int)primes.size(); i++)
		if (N % primes[i] == 0) return false;
	return true;
} // ("primes"�� ����� ������ �Ҽ�)^2 ���� �Ǵ� ����

int main() {
	sieve(100000);

	while (1) {
		string str;
		cin >> str;
		if (str == "0")
			break;

		int ans = 0;
		// ���� 1���� 5�ڸ� ���� �߶󳻱�
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
