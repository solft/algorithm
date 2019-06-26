#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

#define NUMBER_OF_ALPHABET 26
// 문자열 정렬을 위한 counting sort와 radix sort
// 모두 대문자 기준으로 하였다.

// Counting Sort
// 입력 문자열이 가지고 있는 문자의 개수를 세고
// 앞 문자부터 개수만큼 더해서 정렬된 문자열을 만든다.
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
// 길이가 같은 문자열 배열을 사전순으로 빠르게 정렬할 때 사용
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