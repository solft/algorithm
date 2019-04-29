#include <iostream>
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
			primes.push_back((int)i); // �Ҽ� ��Ͽ� �߰�.
		}
	}
}

// 11502�� �� ���� �Ҽ�����
// Ǯ��:
//		�Ҽ��� ���ؼ� �������� �������� ����
//		����� ���̽��� �۾Ƽ� ���Ʈ������ �����Ѱ� �� ��������
//		����� ����ߴ�.
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