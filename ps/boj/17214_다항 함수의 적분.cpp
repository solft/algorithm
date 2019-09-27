#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

// 17214�� ���� �Լ��� ����
// �з�: ���ڿ�
// ����:
//		���������� ���׽��� �־�����
//		�̸� ������ ���� ���ϴ� ����
// Ǯ��:
//		������ ���� �־��� �־
//		�ش��ϴ� ���ǿ� �°� ������ ����� 
//		����Ѵ�.
int main() {
	string poly;
	cin >> poly;
	if (poly.find('x') == string::npos) {
		int check = stoi(poly);
		string xc;
		if (check == 1)
			xc = "";
		else if (check == -1)
			xc = "-";
		else
			xc = poly;
		string ans = xc + "x+W";
		if (check == 0)
			ans = "W";
		cout << ans;
	}
	else {
		int front = stoi(poly.substr(0, poly.find('x'))) / 2;
		string xxc;
		if (front == 1)
			xxc = "";
		else if (front == -1)
			xxc = "-";
		else
			xxc = to_string(front);
		string back = poly.substr(poly.find('x')+1, poly.length() - 1);
		int backNum; 
		string backAns;
		if (back != "") {
			backNum = stoi(back);
			if (backNum == 1)
				backAns = "+";
			else if (backNum == -1)
				backAns = "-";
			else if (backNum > 0)
				backAns = "+" + to_string(backNum);
			else if (backNum < 0)
				backAns = to_string(backNum);
			backAns += "x+W";
		}
		else {
			backAns = "+W";
		}
		string ans = xxc + "xx" + backAns;
		cout << ans;
	}
}