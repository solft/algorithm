#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 1303번 전쟁 - 전투
// 분류: DFS
// 문제:
//		같은 문자로 인접한 덩어리 개수의 제곱을 더한 값을 구하는 문제
// 풀이:
//		방문하지 않은 문자에서 시작해서 같은 문자로 DFS해서 카운팅하고
//		더 이상 진행되지 않으면 센 숫자로 값을 계산하고
//		이를 반복한다.
int n, m;
char battleField[101][101];
int visit[101][101];
int wPower = 0;
int bPower = 0;

int my[4] = { -1, 0, 1, 0 };
int mx[4] = { 0, 1, 0, -1 };
int counter = 0;

void dfs(int y, int x, char ally) {
	counter++;

	for (int i = 0; i < 4; i++) {
		if (y + my[i] < 0 || y + my[i] >= m || x + mx[i] < 0 || x + mx[i] >= n) {
			continue;
		}
		else {
			if (visit[y + my[i]][x + mx[i]] == 1)
				continue;

			if (battleField[y + my[i]][x + mx[i]] == ally) {
				
				visit[y + my[i]][x + mx[i]] = 1;
				dfs(y + my[i], x + mx[i], ally);
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> battleField[i];
	}

	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] != 1) {
				counter = 0;
				visit[i][j] = 1;
				dfs(i, j, battleField[i][j]);

				if (battleField[i][j] == 'W')
					wPower += counter * counter;
				else
					bPower += counter * counter;
			}
		}
	}

	cout << wPower << " " << bPower << '\n';
}