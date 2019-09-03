#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 4949번 균형잡힌 세상
// 분류: 스택
// 문제:
//		스택으로 괄호 성립하는지 체크
// 풀이:
//		스택에 괄호 시작하면 넣고 끝나면 빼내서 최종적으로 스택이 비어있는지 체크

int main() {

	while (1) {
		char str[110];

		fgets(str, 110, stdin);

		string line(str);

		if (line == ".\n")
			break;

		stack<char> parenthesis;

		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '(') {
				parenthesis.push('(');
			}
			else if (line[i] == ')') {
				if (!parenthesis.empty() && parenthesis.top() == '(') {
					parenthesis.pop();
				}
				else {
					parenthesis.push(')');
					break;
				}
			}
			else if (line[i] == '[') {
				parenthesis.push('[');
			}
			else if (line[i] == ']') {
				if (!parenthesis.empty() && parenthesis.top() == '[') {
					parenthesis.pop();
				}
				else {
					parenthesis.push(']');
					break;
				}
			}
		}

		if (parenthesis.empty())
			printf("yes\n");
		else
			printf("no\n");
	}
}