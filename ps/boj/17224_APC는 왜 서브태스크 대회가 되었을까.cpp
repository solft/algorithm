#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 17224�� APC�� �� �����½�ũ ��ȸ�� �Ǿ�����?
// �з�: ����
// ����:
//		���� ������ �־����� ��� ����Ʈ�� �� Ư�� ���� ������ ������ ���ϴµ� 
//		ū ���ڰ� �� ������ 140�� ��� ���� ���ڸ� ������ 100�� �� �ܿ��� 0���϶�
//		���� ū ������ ��� k�� ����� �� �ִ� ���� ���ϱ�
// Ǯ��:
//		ū ���ڸ� �������� �������� �����Ͽ��� �� ���� �� ���� ������ �� ���ϰ�
//		k�� ������ �������� ������ ���� ���� �����ش�.
int n, l, k;
vector<pair<int, int>> sub;

int main() {
	cin >> n >> l >> k;
	sub.resize(n);
	for (int i = 0; i < n; i++) {
		int sub1, sub2;
		cin >> sub1 >> sub2;
		sub[i] = { sub2, sub1 };
	}
	sort(sub.begin(), sub.end());
	int score = 0;
	int solve = 0;
	for (int i = 0; i < n; i++) {
		if (solve == k)
			break;
		else if (sub[i].first <= l) {
			solve++;
			score += 140;
		}
		else if (sub[i].second <= l) {
			solve++;
			score += 100;
		}
	}
	cout << score << '\n';
}