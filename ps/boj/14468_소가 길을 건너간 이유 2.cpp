#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 114468번 소가 길을 건너간 이유2
// 분류: 구현
// 문제:
//		원형에서 같은 알파벳끼리 선을 그었을 때
//		선이 겹치는 쌍의 개수(교점의 개수)를 구하는 문제
// 풀이:
//		같은 알파벳 사이에 한 개만 있는 다른 알파벳이 있으면 교점이 생긴다.
//		모든 알파벳에 대해 두 번 카운팅 되므로 반으로 나눠준다.
int main() {
	char load[52];
	for (int i = 0; i < 52; i++)
		cin >> load[i];

	int ans = 0;
	// A부터 Z까지 검사
	for (int i = 0; i < 26; i++) {

		int first = true;
		vector<int> count;
		count.assign(26, 0);

		for (int j = 0; j < 52; j++) {

			if (load[j] == 'A' + i) {
				if (first) {
					first = false;
				}
				else {
					break;
				}
			}
			else {
				if (!first) {
					count[load[j] - 'A']++;
				}
			}
		}
		
		for (auto c : count)
			if (c == 1)
				ans++;
	}
	cout << ans / 2 << '\n';
}
