#include <iostream>
#include <stack>
using namespace std;

// 10829�� ������ ��ȯ
// �з�: ������
// ����:
//		�־��� ���� �������� ��ȯ�ϴ� ����
// Ǯ��:
//		2�� �������� �������� �����صд�.
//		�������� ������ 1 ~ 100,000,000,000,000�������� ��� ���µ�
//		���� �� �ڵ�� 0�϶� �ȵȴ�. �׷��� ���� �Ǵµ� �Ҿ����� ���´�.
typedef long long ll;

int main() {
	ll N; 
	cin >> N;
	stack<int> ans;
	while (N != 0LL) {
		ans.push(N % 2LL);
		N /= 2LL;
	}
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
}