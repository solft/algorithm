#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 1759�� ��ȣ �����
// �з�: ��Ʈ��ŷ
// ����:
//		���ĺ��� �ߺ� ���� �־� ������ ���� l¥�� ������ ��� ��ȣ�� 
//		���� ������ ���
// Ǯ��:
//		���� l��ŭ ��� �Լ��� ȣ���ϸ� ���ڿ��� �����
//		���̰� l�� �Ǹ� ������ ���� ������ ����̸� ��� �ϴϸ� �׳� �Ѿ
vector<char> key;
vector<int> visit;
int l, c;

bool passCheck(string pw) {
	int mo = 0;
	int ja = 0;
	for (auto c : pw) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			mo++;
		else
			ja++;
		if (mo >= 1 && ja >= 2)
			return true;
	}
	return false;
}

void dfs(string ans, int index, int count) {

	string next = ans + key[index];

	if (count >= l) {
		if(passCheck(next))
			cout << next << '\n';
	}
	else {
		for(int i=1; index + i < c; i++)
			dfs(next, index + i, count + 1);
	}
}

int main() {
	cin >> l >> c;

	key.resize(c);
	for (int i = 0; i < c; i++)
		cin >> key[i];
	sort(key.begin(), key.end());

	for(int i=0; i <= c - l; i++)
		dfs("", i, 1);
}
