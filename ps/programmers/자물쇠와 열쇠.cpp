#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool check(vector<vector<int>> b, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (b[size + i][size + j] == 0 || b[size + i][size + j] > 1)
				return false;
	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	int m = key.size();
	int n = lock.size();

	// ∞°¥…º∫ ∆«¥‹
	int lockBump = 0;
	int keyBump = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			keyBump += key[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			lockBump += lock[i][j];
	if (keyBump < n * n - lockBump)
		return false;

	vector<vector<int>> rotateKey[4];
	for (int i = 0; i < 4; i++) {
		rotateKey[i].assign(m, vector<int>(m, 0));
	}

	// ø≠ºË »∏¿¸
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			rotateKey[0][i][j] = key[i][j];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			rotateKey[1][i][j] = key[m - j - 1][i];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			rotateKey[2][i][j] = key[m - i - 1][m - j - 1];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			rotateKey[3][i][j] = key[j][m - i - 1];
	
	
	vector<vector<int>> base;
	base.assign(3 * n + 1, vector<int>(3 * n + 1, 0));

	// √ ±‚»≠
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			base[n + i][n + j] = lock[i][j];

	// ø≠ºË »∏¿¸
	for (int rotate = 0; rotate < 4; rotate++) {
		// ø≠ºË ¿ßƒ°
		for (int y = n - m + 1; y < 2 * n; y++) {
			for (int x = n - m + 1; x < 2 * n; x++) {

				// ø≠ºË ª¿‘
				for (int i = 0; i < m; i++)
					for (int j = 0; j < m; j++)
						base[y + i][x + j] += rotateKey[rotate][i][j];

				if (check(base, n))
					return true;

				// ø≠ºË ª©±‚
				for (int i = 0; i < m; i++)
					for (int j = 0; j < m; j++)
						base[y + i][x + j] -= rotateKey[rotate][i][j];

			}
		}
	}
	

	return false;
}

int main() {
	vector<vector<int>> lock;
	vector<vector<int>> key;
	int m, n;

	cin >> m >> n;
	
	key.assign(m, vector<int>(m, 0));
	lock.assign(n, vector<int>(n, 0));
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			cin >> key[i][j];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			cin >> lock[i][j];

	cout<< solution(key, lock) << '\n';
}