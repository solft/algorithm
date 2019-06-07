#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// 17264번 I AM IRONMAN
// 분류: 구현
// 문제:
//		입력에 따라 숫자 늘리고 줄여가며 특정 값을 넘을 때가 있는지 확이하는 문제
// 풀이:
//		문제대로 구현하면 된다. 승리할 때만 set에 저장해서 있는지 검사하였다.
int n, p;
int w, l, g;
set<string> player;

int main() {
	cin >> n >> p;
	cin >> w >> l >> g;
	for (int i = 0; i < p; i++) {
		string player_name;
		char win;
		cin >> player_name >> win;
		if (win == 'W')
			player.insert(player_name);
	}

	int score = 0;
	bool isIron = true;
	for (int i = 0; i < n; i++) {
		string player_name;
		cin >> player_name;
		if (player.find(player_name) != player.end()) {
			score += w;
			if (score >= g)
				isIron = false;
		}
		else {
			if (score - l >= 0)
				score -= l;
		}
	}

	if (isIron)
		cout << "I AM IRONMAN!!\n";
	else
		cout << "I AM NOT IRONMAN!!\n";
}
