#include <iostream>
using namespace std;
// 16546번 Missing Runners
// 문제:
//		1~N 사이 숫자 입력받고
//		안나온 숫자 찾기
// 풀이:
//		입력받은거 체크하고
//		입력안받은거 출력한다.
bool runner[35000];

int main() {
	int n;
	cin >> n;
	int r;
	for (int i = 0; i < n - 1; i++) {
		cin >> r;
		runner[r] = true;
	}
	for(int i=1; i<=n; i++)
		if (!runner[i]) {
			cout << i << endl;
			break;
		}
}