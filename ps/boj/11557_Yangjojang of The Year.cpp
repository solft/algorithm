#include <iostream>
using namespace std;

// 11557 Yangjojang of the year
// 분류: 최댓값 구하기
// 문제:
//		입력 받으며 술 가장 많이 먹은 학교 출력하기
// 풀이:
//		최대가 갱식될 때 이름도 갱신한다.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		string school;
		int alcohol;

		int maxAl = 0;
		string maxSchool = "";
		for (int i = 0; i < n; i++) {
			cin >> school >> alcohol;

			if (maxAl < alcohol) {
				maxAl = alcohol;
				maxSchool = school;
			}
		}
		cout << maxSchool << endl;
	}

}