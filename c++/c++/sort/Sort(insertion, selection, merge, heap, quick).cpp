#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 삽입 정렬
void insertionSort(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (v[j] < v[j - 1])
				swap(v[j], v[j - 1]);
			else
				break;
		}
	}
}

// 선택 정렬
void selectionSort(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		int next = v[i];
		int next_index = i;
		for (int j = i + 1; j < v.size(); j++) {
			if (next > v[j]) {
				next = v[j];
				next_index = j;
			}
		}
		swap(v[i], v[next_index]);
	}
}

// 합병 정렬
void merge(vector<int>& v, int left, int mid, int right) {
	int a = left, b = mid + 1;
	vector<int> temp;
	temp.assign(v.begin(), v.end());

	for (int i = left; i <= right; i++) {
		if (a > mid)
			v[i] = temp[b++];
		else if (b > right)
			v[i] = temp[a++];
		else if (temp[a] < temp[b])
			v[i] = temp[a++];
		else if (temp[a] > temp[b])
			v[i] = temp[b++];
	}
}

void mergeSort(vector<int>& v, int left, int right) {
	if (left >= right) return;
	int mid = left + (right - left) / 2;
	mergeSort(v, left, mid);
	mergeSort(v, mid + 1, right);
	merge(v, left, mid, right);
}

// 힙 정렬
void heapSort(vector<int>& v) {
	priority_queue<int> pq;
	for (auto n : v) {
		pq.push(-n);
	}
	for (int i = 0; i < v.size(); i++) {
		v[i] = -pq.top();
		pq.pop();
	}
}

// 퀵 정렬
int partition(vector<int>& v, int left, int right) {
	int a = left, b = right + 1;
	int pivot = v[left]; // 첫 원소를 pivot으로 잡는다.
	while (true) {
		while (v[++a] <= pivot)
			if (a == right)
				break;
		while (v[--b] >= pivot)
			if (b == left)
				break;
		if (a >= b)
			break;
		swap(v[a], v[b]);
	}
	swap(v[left], v[b]);
	return b;
}

void quickSort(vector<int>& v, int left, int right) {
	if (left >= right) return;
	int fixed = partition(v, left, right);
	quickSort(v, left, fixed - 1);
	quickSort(v, fixed + 1, right);
}

int main() {
	vector<int> num = { 2, 9, 6, 1, 4, 8, 7, 5, 3 };
	cout << "정렬 전 : ";
	for (auto n : num)
		cout << n << " ";
	cout << '\n';

	// insertionSort(num);
	// selectionSort(num);
	// mergeSort(num, 0, num.size() - 1);
	// heapSort(num);
	quickSort(num, 0, num.size() - 1);

	cout << "정렬 후 : ";
	for (auto n : num)
		cout << n << " ";
	cout << '\n';
}
