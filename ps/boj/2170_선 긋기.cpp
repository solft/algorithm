#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 2170�� �� �߱�
// �з�: ������ �˰���
// ����:
//		���п� ���� ��ǥ, ������ ��ǥ�� �־����� ���� �׾�����
//		���������� ��ü ��ǥ���� �� �׾��� ������ ���̸� ���ϴ� ����
// Ǯ��:
//		�׾��� ���� ���� ���� �������� �����ϰ� �ϳ��� ���� �����µ�
//		�������� ��ġ�� ������ ������ ���� ����ؼ� ������ ����Ѵ�.
int main() {
	int ans = 0;
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> line;
	line.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &line[i].first, &line[i].second);
	sort(line.begin(), line.end());

	pair<int, int> section = { line[0].first, line[0].second };
	for (int i = 1; i < n; i++) {
		if (line[i].first > section.second) { // ���� ������ ������ ���
			ans += section.second - section.first;
			section.first = line[i].first;
			section.second = line[i].second;
		}
		else { // ���� ������ �پ��ִ� ���
			if(line[i].second > section.second)
				section.second = line[i].second;
		}
	}
	ans += section.second - section.first;
	printf("%d\n", ans);
}