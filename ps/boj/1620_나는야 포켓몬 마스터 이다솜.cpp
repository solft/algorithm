#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

// 1620번 나는야 포켓몬 마스터 이다솜
// 분류: 자료구조, 이진 탐색
// 문제:
//		데이터가 저장되면 키 or 값이 주어졌을때 매칭되는 값 or 키 찾기
// 풀이:
//		이름이 주어졌을 때 번호 찾는 건 map STL을 이용하였고
//		번호가 주어졌을 때 이름 찾는 건 배열로 찾아주었다.
//		cin, cout이 느려서 cin.tie(NULL); ios_base::sync_with_stdio(false);를 붙여주었다.
map<string, int> pokemon;
string pokemonName[100001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string name;
		cin >> name;
		pokemon[name] = i;
		pokemonName[i] = name;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (atoi(s.c_str()) == 0)
			cout << pokemon[s] << '\n';
		else
			cout << pokemonName[stoi(s)] << '\n';
	}
}