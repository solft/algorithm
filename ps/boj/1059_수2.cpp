#include <iostream>
#include <algorithm>
using namespace std;

// 1059 ��2
//	����: 
//		Lucky Set -> ���� ����
//		���� [A, B] -> A <= ���� <= B, A, B�� ���
//		���� [A, B]�� Unlucky�� �Ƿ��� ���� ���� 
//		��� ������ Lucky Set�� �������
//		Lucky Set�� N�� �־��� ��, N�� �����ϴ� Unlucky ������ ���� ���ϱ�
//	�Է�: 
//		L -> Lucky Set�� ����(50����)
//		Lucky Set -> 1000������ �ߺ����� �ʴ� �ڿ��� ����
//		N -> Lucky Set���� ���� ū ������ �۰ų� ���� �ڿ���
//	Ǯ��:
//		Lucky Set�� �����ϰ� N�� ��� ��ġ�� �ִ��� �˾Ƴ���
//		3���� ��찡 �����µ�
//		1) N�� Lucky Set�� ���� ���� ���
//		2) Lucky Set�� �� ���� ���̿� �ִ� ���
//		3) Lucky Set�� ���� ���� ���ں��� ���� ���
//		������ ��� ���� �� �ִ� ����� ���� �����غ���
//		1) 0
//		2) (N-num[index])*(num[index+1]-N)-1
//		3) N*(num[0]-N)-1
//		���̽����� ������ ������ָ� �ȴ�.
int main() {
	int L;
	int num[55];
	int N;

	cin >> L;
	for (int i = 0; i < L; i++)
		cin >> num[i];
	cin >> N;
	sort(num, num + L);

	int index = -1;
	bool impossible = false;
	for (int i = L - 1; i >= 0; i--) {
		if (N > num[i]) {
			index = i;
			break;
		}
		if (N == num[i]) {
			impossible = true;
			break;
		}
	}

	// N == num[index] => Unlucky ����� �Ұ���
	// num[index] < N < num[index+1] => (N-num[index])*(num[index+1]-N)-1
	// N < num[0] => N*(num[0]-N)-1
	if (impossible) {
		cout << 0 << endl;
	}
	else if(index == -1) {
		cout << N * (num[0] - N) - 1 << endl;
	}
	else {
		cout << (N - num[index])*(num[index + 1] - N) - 1 << endl;
	}
}