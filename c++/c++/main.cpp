#include <iostream>
#include <string>
#include <queue>
using namespace std;

// n 사람수
// a 시작 위치
// formation 다른 사람이 뭘 내는지
int n;
int a;
int aState = 0;
int ans = 0; // 답
int formation[100001]; // 0 = 탈락, 1 = POI, 2 = R, 3 = S, 4 = P
string info;

// return l=l이 패자, r=r이 패자, -1=둘다 패자
int loser(int l, int r) {
	// POI가 있는 경우
	if (formation[l] == 1) {
		if (aState == 0) {
			if (formation[r] == 2) {
				aState = 4;
			}
			else if (formation[r] == 3) {
				aState = 2;
			}
			else if (formation[r] == 4) {
				aState = 3;
			}
		}
		else {
			if (formation[r] == 2) {
				if (aState != 4) {
					aState = 4;
					ans++;
				}
			}
			else if (formation[r] == 3) {
				if (aState != 2) {
					aState = 2;
					ans++;
				}
			}
			else if (formation[r] == 4) {
				if (aState != 3) {
					aState = 3;
					ans++;
				}
			}
		}
		return r;
	}
	else if (formation[r] == 1) {
		if (aState == 0) { // 초기 상태일 경우
			if (formation[l] == 2) {
				aState = 4;
			}
			else if (formation[l] == 3) {
				aState = 2;
			}
			else if (formation[l] == 4) {
				aState = 3;
			}
		}
		else {
			if (formation[l] == 2) {
				if (aState != 4) {
					aState = 4;
					ans++;
				}
			}
			else if (formation[l] == 3) {
				if (aState != 2) {
					aState = 2;
					ans++;
				}
			}
			else if (formation[l] == 4) {
				if (aState != 3) {
					aState = 3;
					ans++;
				}
			}
		}
		return l;
	}
	else { // 없는 경우
		if (formation[l] == formation[r]) {
			return -1; // 둘 다 패배
		}
		else if (formation[l] == 2) {
			if (formation[r] == 3) {
				return r;
			}
			else if (formation[r] == 4) {
				return l;
			}
		}
		else if (formation[l] == 3) {
			if (formation[r] == 2) {
				return l;
			}
			else if (formation[r] == 4) {
				return r;
			}
		}
		else if (formation[l] == 4) {
			if (formation[r] == 2) {
				return r;
			}
			else if (formation[r] == 3) {
				return l;
			}
		}
	}
	return -1;
}

int main(void) {
	cin >> n;
	cin >> a;
	cin >> info;

	// 정보를 이용해 입력하는데
	// stirng의 index와 formation의 index가 다르므로 다르게 설정한다.
	int stringIndex = 0;
	for (int i = 0; i < n; i++) {
		if (i == a) { // POI
			formation[i] = 1;
		}
		else {
			if (info[stringIndex] == 'R') {
				formation[i] = 2;
				stringIndex++;
			}
			else if (info[stringIndex] == 'S') {
				formation[i] = 3;
				stringIndex++;
			}
			else if (info[stringIndex] == 'P') {
				formation[i] = 4;
				stringIndex++;
			}
		}
	}

	while (true) {
		queue<int> round;
		for (int i = 0; i < n; i++)
			if (formation[i] != 0)
				round.push(i);

		if (round.size() == 1)
			break;

		// round에서 2개 빼내서 패자는 0으로 바꿈
		// left, right는 index 값
		while (!round.empty()) {

			// 무조건 1개 이상은 있으므로 하나를 빼내고
			int left = round.front();
			round.pop();
			// 비어있으면 부전승
			if (round.empty()) {
				break;
			}
			// 아니면 빼서 대결
			int right = round.front();
			round.pop();

			// 진 사람의 인덱스 가지고
			int loserIndex = loser(left, right);
			if (loserIndex == -1) {
				formation[left] = 0;
				formation[right] = 0;
			}
			else {
				formation[loserIndex] = 0;
			}
		}
	}

	cout << ans << endl;
	return 0;
}