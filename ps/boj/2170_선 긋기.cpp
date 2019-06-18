#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 2170번 선 긋기
// 분류: 스위핑 알고리즘
// 문제:
//		선분에 왼쪽 좌표, 오른쪽 좌표가 주어지고 선을 그었을때
//		최종적으로 전체 좌표에서 선 그어진 영역의 길이를 구하는 문제
// 풀이:
//		그어진 선을 왼쪽 먼저 기준으로 정렬하고 하나씩 살펴 나가는데
//		합쳐지면 합치고 떨어져 있으면 합을 계산해서 끝까지 계산한다.
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
		if (line[i].first > section.second) { // 다음 선분이 떨어진 경우
			ans += section.second - section.first;
			section.first = line[i].first;
			section.second = line[i].second;
		}
		else { // 다음 선분이 붙어있는 경우
			if(line[i].second > section.second)
				section.second = line[i].second;
		}
	}
	ans += section.second - section.first;
	printf("%d\n", ans);
}