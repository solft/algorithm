#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 15650�� N�� M (2)
// �з�: ��Ʈ��ŷ
// ����:
//		1~N �� M���� ������ �������� ������ ����ϴ� ����
// Ǯ��:
//		N�� �� M���� �����ϴµ� ������ ���� üũ�� �صΰ�
//		������ ������ ���� ���� ū�ź��� ū ������ ����.
//		��� ���ٰ� M���� ���� ���� ���� ����Ѵ�.
int n, m;
vector<int> ans;
int selected[10];

void solution(int count) {

	if (count == m) {
		for (int num : ans)
			cout << num << " ";
		cout << '\n';
	}

	for (int i = ans.back() + 1; i <= n; i++) {
		if (selected[i] == 0) {
			ans.push_back(i);
			selected[i] = 1;
			solution(count + 1);
			selected[i] = 0;
			ans.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		ans = { i };
		solution(1);
	}
}