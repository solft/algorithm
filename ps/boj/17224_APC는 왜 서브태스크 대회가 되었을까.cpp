#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 17224번 APC는 왜 서브태스크 대회가 되었을까?
// 분류: 구현
// 문제:
//		숫자 페어들이 주어지고 페어 리스트들 중 특정 숫자 이하의 개수를 구하는데 
//		큰 숫자가 더 작으면 140점 얻고 작은 숫자만 작으면 100점 그 외에는 0점일때
//		가장 큰 점수를 얻게 k개 고랐을 때 최대 점수 구하기
// 풀이:
//		큰 숫자를 기준으로 오름차순 정렬하여서 두 문제 다 맞출 경우부터 다 구하고
//		k가 남으면 나머지는 가능한 작은 숫자 더해준다.
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