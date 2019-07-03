#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

// 1786�� ã��
// �з�: KMP, ���ڿ� ��Ī
// ����:
//		���� ���ڿ� ��Ī �˰����� ����Ͽ� ���ڿ��� �� ��, ��� �������� ���ϱ�
// Ǯ��:
//		KMP �˰����� ����Ͽ� Ǯ����.
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