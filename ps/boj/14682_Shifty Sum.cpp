#include <iostream>
#include <stack>
using namespace std;

// 14682�� Shifty Sum
// �з�: ����
// ����:
//		n�� �־����� n + n0 + n00 + ... n(k���� 0)�� ���ϱ�
// Ǯ��:
//		n + n*10 + n*100 + ... + n*10^k �� ���Ѵ�.
int solution(int n, int k) {
	int result = 0;
	int shift = 1;
	while (k >= 0) {
		result += shift * n;
		shift *= 10;
		k--;
	}
	return result;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << solution(n, k) << '\n';
}