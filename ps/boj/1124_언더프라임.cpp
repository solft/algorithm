#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

// 1124�� ���������
// �з�: �Ҽ�
// ����:
//		���� �������� ���μ������� �Ҽ� ������ �Ҽ����� ���� ���� ���ϱ�
// Ǯ��:
//		�Ҽ� ���صΰ� �Ҽ��� �̿��� ���μ� ���� �� �Խ� üũ�Ѵ�.
typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<100010> bs; // 10^7���� �Ҽ� ����. bs[i] = 0: i�� 0 or 1 or �ռ���, bs[i] = 1: i�� �Ҽ�
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