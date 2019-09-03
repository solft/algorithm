#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 4949�� �������� ����
// �з�: ����
// ����:
//		�������� ��ȣ �����ϴ��� üũ
// Ǯ��:
//		���ÿ� ��ȣ �����ϸ� �ְ� ������ ������ ���������� ������ ����ִ��� üũ

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