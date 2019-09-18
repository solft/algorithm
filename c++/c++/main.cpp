#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 와일드카드 패턴 w가 문자열 s에 대응되는지 여부를 반환한다.
bool match(const string& w, const string& s) {
	// w[pos]와 s[pos]를 맞춰나간다.
	int pos = 0;
	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
		pos++;
}

int main() {

}