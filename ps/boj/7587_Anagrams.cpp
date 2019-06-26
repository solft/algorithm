#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 7587�� Anagrams
// �з�: anagram
// ����:
//		anagram�� ���� ���� ������ ���ڿ� �߿� ���� ���� ������ ���ڿ��� ����ϴ� ����
// Ǯ��:
//		counting sort�� �̿��� �Է� ���ڿ��� ��� ���Ľ�Ű��
//		��� ���ڿ� ����Ʈ�� ���Ľ��Ѽ� ���ĵ� ���ڿ��� anagram ������ ���Ѵ�.
//		�׸��� ���� ���ڿ� ����Ʈ�� ó������ ���캸��
//		�ִ� anagram ������ ������ ù��° ���ڿ��� ����Ѵ�.
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