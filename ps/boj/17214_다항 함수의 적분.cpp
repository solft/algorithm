#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

// 17214번 다항 함수의 적분
// 분류: 문자열
// 문제:
//		일차이하의 다항식이 주어지고
//		이를 적분한 식을 구하는 문제
// 풀이:
//		조건이 쉽게 주어져 있어서
//		해당하는 조건에 맞게 적분한 결과를 
//		출력한다.
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