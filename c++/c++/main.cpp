#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// ���ϵ�ī�� ���� w�� ���ڿ� s�� �����Ǵ��� ���θ� ��ȯ�Ѵ�.
bool match(const string& w, const string& s) {
	// w[pos]�� s[pos]�� ���糪����.
	int pos = 0;
	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
		pos++;
}

int main() {

}