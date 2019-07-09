#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// a=text, b=pattern
string text, pattern;
vector<int> p;
vector<int> costSum;

void kmp() {
	int j = 0;
	for (int i = 0; i < text.length(); i++) {
		while (j > 0 && text[i] != pattern[j])
			j = p[j - 1];
		if (text[i] == pattern[j]) {
			if (j == pattern.length() - 1) {
				costSum.push_back(i - pattern.length() + 1);
				j = p[j];
			}
			else
				j++;
		}
	}
}

void failure() {
	int j = 0;
	for (int i = 1; i < pattern.length(); i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = p[j - 1];
		if (pattern[i] == pattern[j])
			p[i] = ++j;
	}
}

int main() {
	text = "ABABBABABCABB";
	pattern = "ABABC";

	p.resize(pattern.length());
	failure();
	kmp();

	for (auto k : p)
		cout << k << '\n';

	for (auto k : costSum)
		cout << k << '\n';
}