#include <iostream>
#include <algorithm>
#include <queue>
using namespace std; 

// 14502번 연구소
// 분류: BFS, 브루트포스
// 문제: 
//		2차원 배열에 3곳을 1로 바꾸고 2인 곳에서 시작해서
//		상하좌우로 0인 곳을 2로 바꿔나갈 때 최종적으로
//		남아있는 0의 개수가 최대인 경우를 구하는 문제
// 풀이:
//		브루트포스로 1을 설정할 3곳을 정하고
//		해당 케이스에 대해 BFS로 2를 퍼뜨리고
//		남아있는 0의 개수를 카운트해서 최대 값을 구한다.
int n, m;
int lab[8][8];

void printState(int arr[][8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

void bfs(int arr[][8]) {
	int mr[4] = { -1, 0, 1, 0 };
	int mc[4] = { 0, 1, 0, -1 };

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 2)
				q.push(pair<int, int>(i, j));

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (now.first + mr[i] >= 0 && now.first + mr[i] < n && now.second + mc[i] >= 0 && now.second + mc[i] < m) {
				if (arr[now.first + mr[i]][now.second + mc[i]] == 0) {
					arr[now.first + mr[i]][now.second + mc[i]] = 2;
					q.push(pair<int, int>(now.first + mr[i], now.second + mc[i]));
				}
			}
		}
	}
}

int countSafe(int arr[][8]) {
	int counter = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 0)
				counter++;
	return counter;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> lab[i][j];


	int ans = 0;
	for (int i = 0; i < m * n; i++) {
		if (lab[i / m][i % m] == 0) {
			lab[i / m][i % m] = 1;
			for (int j = i + 1; j < m * n; j++) {
				if (lab[j / m][j % m] == 0) {
					lab[j / m][j % m] = 1;
					for (int k = j + 1; k < m * n; k++) {
						if (lab[k / m][k % m] == 0) {
							lab[k / m][k % m] = 1;
							// 여기서 복사하고
							int temp[8][8];
							copy(&lab[0][0], &lab[0][0] + 64, &temp[0][0]);
							//printState(temp);
							//cout << endl;
							// BFS
							bfs(temp);
							int tempSafe = countSafe(temp);
							if (ans < tempSafe)
								ans = tempSafe;
							lab[k / m][k % m] = 0;
						}
					}
					lab[j / m][j % m] = 0;
				}
			}
			lab[i / m][i % m] = 0;
		}
	}
	cout << ans << endl;
}