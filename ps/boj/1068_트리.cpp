#include <iostream>
using namespace std; 
// 1068�� Ʈ��
// ����:
//		Ʈ������ ����� �θ� ��� ��ȣ�� �־����� ��
//		��� ��� �ϳ��� ������ ��, Ʈ���� ������� ������ ���� ����
// Ǯ��:
//		������ ��� ������ ����� �θ� Ư�������� ���� ǥ���ϰ�
//		��� ��忡�� ���� �˻縦 �ؼ� ��Ʈ�� ������� ������ �Ȱ��� ���� ó���ߴ�.
//		�׸��� ������� ã�� ������ �θ� ��� ������ ���� ��常 ���� ����̹Ƿ�
//		�θ��� ����̰ų� null�� ��带 isLeaf���� false�ϰ� true�� ī��Ʈ �ߴ�.
int parent[51];
bool isLeaf[51];
int delNode;

// v�� ����� ������ �˻�
bool checkConnect(int v) {
	int now = v;
	while (now != -1) {
		if (parent[now] == -100)
			return false;
		now = parent[now];
	}
	return true;
}

int main() {
	// -100�� �θ� ���� ����
	for (int i = 0; i < 50; i++)
		parent[i] = -100;
		
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> parent[i];
		isLeaf[i] = true;
	}
		
	cin >> delNode;
	parent[delNode] = -100;

	for (int i = 0; i < n; i++)
		if (!checkConnect(i)) {
			parent[i] = -100;
			isLeaf[i] = false;
		}
			

	for (int i = 0; i < n; i++) {
		if (parent[i] >= 0)
			isLeaf[parent[i]] = false;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (isLeaf[i])
			ans++;
	cout << ans << endl;
}