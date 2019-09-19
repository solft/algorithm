#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 15651�� N�� M (3)
// �з�: ��Ʈ��ŷ
// ����:
//		�ߺ��� ����ؼ� 1~N �� M���� ���� ���
//		��� ����ϴ� ����
//	Ǯ��:
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

	for (int i = 1; i <= n; i++) {
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