#include <iostream>
#include <queue>

using namespace std;

// 1107번 리모컨
// 분류: 브루트포스
// 문제:
//		리모콘에서 몇 개의 숫자 번호가 고장 났을 때
//		남은 숫자와 -, +로 원하는 번호까지 최소 몇 번으로 갈 수 있는지 구하는 문제
// 풀이:
//		여러 케이스가 있는데 원하는 채널이 100인 경우(안움직여도 됨)
//		처음부터 -, +로 찾아가는 경우
//		고장나지 않았다는 가정하에 번호로 바로 가는 경우
//		고장나지 않은 가장 인접한 번호 누른 뒤 -, +로 찾아가는 경우
//		등등을 고려해서 결국은 한 번호씩 줄이거나 늘려가며(줄이는거 먼저 확인해야됨)
//		해당 번호를 찾으면 최소 누른 횟수를 구할 수 있게 된다.
int now = 100;
int n, m;
int breakdown[10];

// -1 바로 가지 못함, result번 눌러야 감
int isPush(int channel) {
	if (channel < 0)
		return -1;
	int result = 0;
	do {
		if (breakdown[channel % 10])
			return -1;
		channel /= 10;
		result++;
	} while (channel != 0);
	return result;
}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int breakNum;
		cin >> breakNum;
		breakdown[breakNum] = 1;
	}

	// -,+ 로만 이동 시
	int onlyMinusPlus = abs(n - now);

	// 해당 수로 바로가기
	int direct = isPush(n);

	if (n == now)
		cout << 0 << '\n';
	else if (direct >= 0) {
		if (onlyMinusPlus < direct)
			cout << onlyMinusPlus << '\n';
		else
			cout << direct << '\n';
	}
	else {
		int pushPlus = n;
		int pushMinus = n;
		bool noAns = true;

		for (int i = 1; i <= onlyMinusPlus; i++) {
			int isPushPlus = isPush(pushPlus + i);
			int isPushMinus = isPush(pushMinus - i);

			if (isPushMinus >= 0) {
				if (isPushMinus + i < onlyMinusPlus)
					cout << isPushMinus + i << '\n';
				else
					cout << onlyMinusPlus << '\n';
				noAns = false;
				break;
			}

			if (isPushPlus >= 0) {
				if (isPushPlus + i < onlyMinusPlus)
					cout << isPushPlus + i << '\n';
				else
					cout << onlyMinusPlus << '\n';
				noAns = false;
				break;
			}
		}

		if (noAns)
			cout << onlyMinusPlus << '\n';
	}
}