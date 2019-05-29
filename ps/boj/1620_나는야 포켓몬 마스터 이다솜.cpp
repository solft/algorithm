#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

// 1620�� ���¾� ���ϸ� ������ �̴ټ�
// �з�: �ڷᱸ��, ���� Ž��
// ����:
//		�����Ͱ� ����Ǹ� Ű or ���� �־������� ��Ī�Ǵ� �� or Ű ã��
// Ǯ��:
//		�̸��� �־����� �� ��ȣ ã�� �� map STL�� �̿��Ͽ���
//		��ȣ�� �־����� �� �̸� ã�� �� �迭�� ã���־���.
//		cin, cout�� ������ cin.tie(NULL); ios_base::sync_with_stdio(false);�� �ٿ��־���.
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