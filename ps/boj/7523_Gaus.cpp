#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 7523�� Gaus
// �з�: ����
// ����:
//		n���� m���� ������ �� ���ϱ�
// Ǯ��:
//		n~m �� = ((n+m)*(m-n+1))/2
typedef long long ll;

int main() {
	int t;
	cin >> t;
	for(int i=1; i<=t; i++){
		ll n, m;
		cin >> n >> m;
		cout <<"Scenario #"<< i<<":\n" << (n + m) * (m - n + 1) / 2 << "\n\n";
	}
}