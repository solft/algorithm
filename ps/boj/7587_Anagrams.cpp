#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 7587번 Anagrams
// 분류: anagram
// 문제:
//		anagram을 가장 많이 가지는 문자열 중에 가장 먼저 나오는 문자열을 출력하는 문제
// 풀이:
//		counting sort를 이용해 입력 문자열을 모두 정렬시키고
//		모든 문자열 리스트를 정렬시켜서 정렬된 문자열의 anagram 개수를 구한다.
//		그리고 원본 문자열 리스트를 처음부터 살펴보며
//		최대 anagram 개수를 가지는 첫번째 문자열을 출력한다.
#define NUMBER_OF_ALPHABET 26

string countingSort(string str) {
	int alphabets[NUMBER_OF_ALPHABET] = { 0, };
	for (auto c : str)
		alphabets[c - 'a']++;

	string result = "";
	for (int i = 0; i < NUMBER_OF_ALPHABET; i++)
		for (int j = 0; j < alphabets[i]; j++)
			result += char('a' + i);

	return result;
}

int main() {
	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;

		vector<string> strList;
		vector<string> anagramList;
		strList.resize(n);
		anagramList.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> strList[i];
			anagramList[i] = countingSort(strList[i]);
		}

		sort(anagramList.begin(), anagramList.end());

		unordered_map<string, int> anagramCounter;
		int mostAnagramCounter = 1;
		for (int i = 0; i < n; i++) {
			if (anagramCounter.count(anagramList[i]) == 0)
				anagramCounter[anagramList[i]] = 1;
			else {
				int tempAnagramCounter = ++anagramCounter[anagramList[i]];
				if (mostAnagramCounter < tempAnagramCounter)
					mostAnagramCounter = tempAnagramCounter;
			}
		}


		for (int i = 0; i < n; i++) {
			if (anagramCounter[countingSort(strList[i])] == mostAnagramCounter) {
				cout << strList[i] << " " << mostAnagramCounter - 1 << '\n';
				break;
			}
		}
	}
}