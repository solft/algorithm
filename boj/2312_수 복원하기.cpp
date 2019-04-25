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
		}
		primes.push_back((int)i); // �Ҽ� ��Ͽ� �߰�.
	}
}

// 2312�� �� �����ϱ�
// ����: 
//		���� ���� N�� ���μ������� ����� ����ϴ� �����̴�.
//		�Ҽ��� �̿��� Ǭ��.
// Ǯ��:
//		���μ��� �������� ���ؾ� �ϹǷ� �Ҽ��� ���صΰ�
//		�������� ���μ��� ī��Ʈ�� �������Ѱ��� �����ߴ�.
//		�ε����� �� �ǹ��ϴ��� �ε����� ������ ����� 
//		�ξ�� �� �� �����ϸ�ȴ�.
vector<int> ans;

int main() {
	// 100000 ������ �Ҽ� ��� ����
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