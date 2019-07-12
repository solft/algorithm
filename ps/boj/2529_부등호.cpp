#include <iostream>
using namespace std;

// 2529번 부등호
// 분류: 그리디
// 문제:
//		부등호 배열이 주어지고 해당 부등호를 만족하게
//		0 ~ 9까지 수 중 하나씩 넣을 때 만들어진 숫자의 최대, 최소 구하기
// 풀이:
//		작은 숫자는 작은 수부터 큰 숫자는 큰 수 부터 들어갈 최적의
//		자리를 찾은 뒤에 채워나간다.
int k;
char sign[11];
int max_ans[11];
int min_ans[11];

int main() {
	cin >> k;
	for (int i = 0; i < k + 1; i++)
		max_ans[i] = min_ans[i] = -1;

	for (int i = 0; i < k; i++)
		cin >> sign[i+1];

	// 들어가는 숫자
	for (int i = 0; i < k+1; i++) {
		// 들어갈 자리
		int index = 0;
		while (index < k) {
			if (min_ans[index] == -1) {
				if (sign[index + 1] == '<')
					break;
				else if (sign[index + 1] == '>') {
					if (min_ans[index + 1] == -1)
						index++;
					else
						break;
				}
				else
					index++;
			}
			else
				index++;
		}
		min_ans[index] = i;
	}

	// 들어가는 숫자
	for (int i = 0; i < k + 1; i++) {
		int input_number = 9 - i;
		// 들어갈 자리
		int index = 0;
		while (index < k) {
			if (max_ans[index] == -1) {
				if (sign[index + 1] == '>')
					break;
				else if (sign[index + 1] == '<') {
					if (max_ans[index + 1] == -1)
						index++;
					else
						break;
				}
				else
					index++;
			}
			else
				index++;
		}
		max_ans[index] = input_number;
	}

	for (int i = 0; i < k + 1; i++)
		cout << max_ans[i];
	cout << '\n';
	for (int i = 0; i < k+1; i++)
		cout << min_ans[i];
	cout << '\n';
}