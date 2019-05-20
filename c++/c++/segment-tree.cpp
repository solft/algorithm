#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define INF 2000000000

int n; // ������ ����
int input_array[10000];
int segment[10000];

int init(int node, int begin, int end) {
	if (begin == end) return segment[node] = input_array[begin];
	int mid = (begin + end) / 2;
	return segment[node] = init(node * 2, begin, mid) + init(node * 2 + 1, mid + 1, end);
}

int segment_sum(int a, int b) {
	a += n; b += n;
	int s = 0;
	while (a <= b) {
		if (a % 2 == 1) s += segment[a++];
		if (b % 2 == 0) s += segment[b--];
		a /= 2; b /= 2;
	}
	return s;
}

// input_array[k] ���Ҹ� x ��ŭ ����
void update(int k, int x) {
	k += n;
	segment[k] += x;
	for (k /= 2; k >= 1; k /= 2)
		segment[k] = segment[2 * k] + segment[2 * k + 1];
}

// ���׸�Ʈ Ʈ��(Segment Tree)
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> input_array[i];

	// ���׸�Ʈ Ʈ���� ũ�� ���ϱ�
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));

	cout << "h = " << h << ", tree_size = " << tree_size << '\n';

	// ���׸�Ʈ Ʈ�� �ʱ�ȭ
	init(1, 1, n);

	for (int i = 1; i <= tree_size; i++)
		cout << segment[i] << ' ';
	cout << '\n';

	cout << "�κ��� ���ϱ�\n";
	while (1) {
		int left, right;
		cout << "������ �Է��ϼ���(0,0) �Է½� ����:  ";
		cin >> left >> right;
		if (left == 0 && right == 0)
			break;
		cout << segment_sum(left, right) << '\n';
	}

	cout << "�� ������Ʈ\n";
	while (1) {
		int target, increase;
		cout << "������Ʈ�� ������ �Է��ϼ���.(0,0) �Է½� ����:  ";
		cin >> target >> increase;
		if (target == 0 && right == 0)
			break;
		update(target, increase);
		for (int i = 1; i <= tree_size; i++)
			cout << segment[i] << ' ';
		cout << '\n';
	}
}