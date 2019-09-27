#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// 14888�� ������ �����ֱ�
// �з�: ���Ʈ ����
// ����: 
//		�����ڸ� �ƹ� ������ ��ġ�� ��
//		���� �� �ִ� ����� �ִ�, �ּ� ���ϱ�
// Ǯ��:
//		������ ��� ������ �ؼ� �ִ񰪰� �ּڰ���
//		������Ʈ �Ѵ�.
int n;
vector<int> numbers;
vector<int> operators(4);
int maxSolution = -2000000000;
int minSolution = 2000000000;

void calculate(int now, int opsCounting) {

	if (opsCounting == 0) {
		if (maxSolution < now)
			maxSolution = now;
		if (minSolution > now)
			minSolution = now;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operators[i] >= 1) {
			if (i == 0) {
				operators[i]--;
				calculate(now + numbers[n - opsCounting], opsCounting - 1);
				operators[i]++;
			}
			else if (i == 1) {
				operators[i]--;
				calculate(now - numbers[n - opsCounting], opsCounting - 1);
				operators[i]++;
			}
			else if (i == 2) {
				operators[i]--;
				calculate(now * numbers[n - opsCounting], opsCounting - 1);
				operators[i]++;
			}
			else if (i == 3) {
				operators[i]--;
				calculate(now / numbers[n - opsCounting], opsCounting - 1);
				operators[i]++;
			}
		}
	}
}

int main() {
	cin >> n;
	numbers.resize(n);
	int initialOps = 0;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
		initialOps += operators[i];
	}
		
	calculate(numbers[0], initialOps);

	cout << maxSolution << '\n' << minSolution << '\n';
}