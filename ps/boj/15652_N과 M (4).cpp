#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 15652�� N�� M (4)
// �з�: ��Ʈ��ŷ
// ����:
//		�ߺ��� ����ؼ� 1~N �� M���� ���� ���
//		�񳻸��������� ����ϴ�
//	Ǯ��:
//		���� ������ �������� �̻����� �����ؼ�
//		������ �� ó������ �� �����ϵ��� �ϰ�
//		���������� M���� �������� ���� �Ѵ�.
int n, m;
vector<int> ans;

void solution(int count) {

	if (count == m) {
		for (int num : ans)
			printf("%d ", num);
		printf("\n");
		return;
	}

	for (int i = ans.back(); i <= n; i++) {
		ans.push_back(i);
		solution(count + 1);
		ans.pop_back();
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		ans = { i };
		solution(1);
	}
}