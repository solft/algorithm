#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 1041�� �ֻ���
// �з�: ����, �ּڰ� ã��
// ����:
//		�ֻ����� �ٴڿ� ������ �� ���̴� ���� �ּڰ��� ���ϴ� ����
// Ǯ��:
//		1��, 2��, 3���� �ּڰ� ���ϰ� �ٴڿ� ������ �� ���̴� ���� ���� ���� �����ش�.
typedef long long ll;
#define INF 100000000
ll n;
ll a[6];

ll find_one_min() {
	ll result = INF;
	for (int i = 0; i < 6; i++)
		if (result > a[i])
			result = a[i];
	return result;
}

ll find_two_min() {
	ll result = INF;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == j || i + j == 5) // ���� �鳢�� ���ϰų� �ݴ��� �鳢�� ���ϴ� ���
				continue;
			ll temp = a[i] + a[j];
			if (result > temp)
				result = temp;
		}
	}
	return result;
}

ll find_three_min() {
	ll result = INF;
	// ABC, ACE, AED, ABD
	if (result > a[0] + a[1] + a[2])
		result = a[0] + a[1] + a[2];
	if (result > a[0] + a[1] + a[3])
		result = a[0] + a[1] + a[3];
	if (result > a[0] + a[2] + a[4])
		result = a[0] + a[2] + a[4];
	if (result > a[0] + a[3] + a[4])
		result = a[0] + a[3] + a[4];
	// FBC, FCE, FED, FBD
	if (result > a[5] + a[1] + a[2])
		result = a[5] + a[1] + a[2];
	if (result > a[5] + a[1] + a[3])
		result = a[5] + a[1] + a[3];
	if (result > a[5] + a[2] + a[4])
		result = a[5] + a[2] + a[4];
	if (result > a[5] + a[3] + a[4])
		result = a[5] + a[3] + a[4];
	return result;
}

int main() {
	cin >> n;
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	// n == 1 �� ���
	// �غκ� : ���� ū ���� �ظ����� ���Բ�
	if (n == 1) {
		ll ans = 0;
		ll die_max = 0;
		for (int i = 0; i < 6; i++) {
			ans += a[i];
			if (die_max < a[i])
				die_max = a[i];
		}
		cout << ans - die_max << '\n';
	}
	// n == 2 �� ��� 
	// ���κ� : 3���� ���� ���� ���� ��� * 4
	// �غκ� : 2���� ���� ���� ���� ��� * 4
	else if (n == 2) {
		cout << find_three_min() * 4LL + find_two_min() * 4LL << '\n';
	}
	// n >= 3 �� ��� 
	// ���κ� : 3���� ���� ���� ���� ��� * 4 + 2���� ���� ���� ���� ��� * (n-2) * 8 + ���� ���� �� * (n-2)*(n-2) * 5
	// �غκ� : 2���� ���� ���� ���� ��� * 4 + ���� ���� �� * (n-2) * 4
	else if (n >= 3) {
		cout << find_three_min() * 4LL + find_two_min() * (8LL * n - 12LL) + find_one_min() * (5LL * n * n - 16LL * n + 12LL) << '\n';
	}
}