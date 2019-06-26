#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

#define NUMBER_OF_ALPHABET 26
// ���ڿ� ������ ���� counting sort�� radix sort
// ��� �빮�� �������� �Ͽ���.

// Counting Sort
// �Է� ���ڿ��� ������ �ִ� ������ ������ ����
// �� ���ں��� ������ŭ ���ؼ� ���ĵ� ���ڿ��� �����.
string countingSort(string str) {
	int alphabets[NUMBER_OF_ALPHABET] = { 0, };
	for (auto c : str)
		alphabets[c - 'A']++;

	string result = "";
	for (int i = 0; i < NUMBER_OF_ALPHABET; i++)
		for (int j = 0; j < alphabets[i]; j++)
			result += char('A' + i);

	return result;
}

// Radix Sort
// ���̰� ���� ���ڿ� �迭�� ���������� ������ ������ �� ���
void radixSort(vector<string>& v) {
	int str_idx = v[0].length() - 1;
	vector<queue<string>> buckets;
	buckets.resize(NUMBER_OF_ALPHABET);

	while (str_idx >= 0) {
		for (int i = 0; i < v.size(); i++)
			buckets[v[i][str_idx] - 'A'].push(v[i]);

		int v_idx = 0;
		for (int i = 0; i < 26; i++) {
			while (!buckets[i].empty()) {
				v[v_idx++] = buckets[i].front();
				buckets[i].pop();
			}
		}

		str_idx--;
	}
}

int main() {
	// Counting sort TEST
	cout << countingSort("COUNTINGSORT") << '\n';

	// Radix sort TEST
	vector<string> radix;
	radix.resize(10);
	radix[0] = "RADIXS";
	radix[1] = "RADIOS";
	radix[2] = "BANANA";
	radix[3] = "AUDIOS";
	radix[4] = "BOSTON";
	radix[5] = "CANADA";
	radix[6] = "MANAGE";
	radix[7] = "DOCKER";
	radix[8] = "CAMERA";
	radix[9] = "DONATE";
	radixSort(radix);
	for (auto s : radix)
		cout << s << '\n';
}