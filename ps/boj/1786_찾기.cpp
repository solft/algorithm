#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

// 1786번 찾기
// 분류: KMP, 문자열 매칭
// 문제:
//		빠른 문자열 매칭 알고리즘을 사용하여 문자열이 몇 번, 어디서 나오는지 구하기
// 풀이:
//		KMP 알고리즘을 사용하여 풀었다.
string text, pattern;
vector<int> p;
vector<int> ans;

void kmp() {
	int j = 0;
	for (unsigned int i = 0; i < text.length(); i++) {
		while (j > 0 && text[i] != pattern[j])
			j = p[j - 1];
		if (text[i] == pattern[j]) {
			if (j == pattern.length() - 1) {
				ans.push_back(i - pattern.length() + 1);
				j = p[j];
			}
			else
				j++;
		}
	}
}

void failure() {
	int j = 0;
	for (unsigned int i = 1; i < pattern.length(); i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = p[j - 1];
		if (pattern[i] == pattern[j])
			p[i] = ++j;
	}
}

int main() {
	getline(cin, text);
	getline(cin, pattern);

	p.resize(pattern.length());
	failure();
	kmp();

	cout << ans.size() << '\n';
	for (auto k : ans)
		cout << k + 1 << ' ';
	cout << '\n';
}