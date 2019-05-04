#include <iostream>
using namespace std; 
// 1068번 트리
// 문제:
//		트리에서 노드의 부모 노드 번호가 주어졌을 때
//		어느 노드 하나를 삭제한 뒤, 트리의 리프노드 개수를 새는 문제
// 풀이:
//		삭제의 경우 삭제한 노드의 부모를 특정값으로 삭제 표시하고
//		모든 노드에서 조상 검사를 해서 루트에 연결되지 않으면 똑같이 삭제 처리했다.
//		그리고 리프노드 찾는 과정은 부모 노드 정보에 없는 노드만 리프 노드이므로
//		부모인 노드이거나 null인 노드를 isLeaf에서 false하고 true만 카운트 했다.
int parent[51];
bool isLeaf[51];
int delNode;

// v번 노드의 조상을 검사
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
	// -100은 부모가 없는 상태
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