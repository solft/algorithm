#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 10830�� ��� ����
// �з�: ��������
// ����:
//		����� ������ ������ ���ϴ� ����
//	Ǯ��:
//		2M�̸� M * M ���� �и��ϰ�
//		2M + 1�̸� 2M * 1�� �и��Ѵ�.
int n;
long b;
vector<vector<int>> matrix;

vector<vector<int>> identity(int size) {
	vector<vector<int>> ret;
	ret.assign(size, vector<int>(size, 0));
	for (int i = 0; i < size; i++)
		ret[i][i] = 1;
	return ret;
}

vector<vector<int>> multiple(vector<vector<int>> a, vector<vector<int>> b) {
	vector<vector<int>> ret;
	ret.assign(a.size(), vector<int>(a.size(), 1));

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			int temp = 0;
			for (int k = 0; k < a.size(); k++) {
				temp += a[i][k] * b[k][j];
				temp %= 1000;
			}
			ret[i][j] = temp;
		}
	}

	return ret;
}

vector<vector<int>> solution(vector<vector<int>> mat, long m) {

	if (m == 0) 
		return identity(mat.size());

	if (m % 2 == 1)
		return multiple(solution(mat, m - 1), mat);

	vector<vector<int>> ret = solution(mat, m / 2);

	return multiple(ret, ret);
}

int main() {
	cin >> n >> b;
	matrix.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];

	vector<vector<int>> sol = solution(matrix, b);

	for (vector<int> line : sol) {
		for (int num : line) {
			cout << num << ' ';
		}
		cout << '\n';
	}
}