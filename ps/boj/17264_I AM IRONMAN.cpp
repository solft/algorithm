#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// 17264�� I AM IRONMAN
// �з�: ����
// ����:
//		�Է¿� ���� ���� �ø��� �ٿ����� Ư�� ���� ���� ���� �ִ��� Ȯ���ϴ� ����
// Ǯ��:
//		������� �����ϸ� �ȴ�. �¸��� ���� set�� �����ؼ� �ִ��� �˻��Ͽ���.
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
