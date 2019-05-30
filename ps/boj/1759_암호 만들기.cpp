#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 1759번 암호 만들기
// 분류: 백트래킹
// 문제:
//		알파벳이 중복 없이 주어 졌을때 길이 l짜리 가능한 비밀 번호를 
//		사전 순으로 출력
// 풀이:
//		길이 l만큼 계속 함수를 호출하며 문자열을 만들고
//		길이가 l이 되면 조건을 따져 가능한 비번이면 출력 하니면 그냥 넘어감
vector<char> key;
vector<int> visit;
int l, c;

bool passCheck(string pw) {
	int mo = 0;
	int ja = 0;
	for (auto c : pw) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			mo++;
		else
			ja++;
		if (mo >= 1 && ja >= 2)
			return true;
	}
	return false;
}

void dfs(string ans, int index, int count) {

	string next = ans + key[index];

	if (count >= l) {
		if(passCheck(next))
			cout << next << '\n';
	}
	else {
		for(int i=1; index + i < c; i++)
			dfs(next, index + i, count + 1);
	}
}

int main() {
	cin >> l >> c;

	key.resize(c);
	for (int i = 0; i < c; i++)
		cin >> key[i];
	sort(key.begin(), key.end());

	for(int i=0; i <= c - l; i++)
		dfs("", i, 1);
}
