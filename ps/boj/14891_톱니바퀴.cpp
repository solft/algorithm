#include <iostream>
using namespace std;

// 14891번 톱니바퀴
// 분류: 구현
// 문제:
//		톱니바퀴 축의 극이 다를 경우 연쇄적으로 돌아가도록
//		구현한 뒤에 특정 톱니를 시계, 반시계 방향으로
//		몇 번 회전 시킨 후 12시 방향에 S극이 몇 개인지 구하는 문제
// 풀이:
//		다른 톱니와 접촉하는 부분만 인덱스를 따로 저장해서
//		그 부분끼리 비교해 회전하는 톱니만 구한 뒤
//		회전시킨다. 그리고 최종적으로 해당 인덱스에서 
//		12시 방향 위치까지의 상대 위치를 찾아내어 12시 값을 구한다.

int checkRange(int num) {
	if (num > 7)
		return 0;
	else if (num < 0)
		return 7;
	else
		return num;
}

int main() {
	char sawtooth[4][9];
	int idxPointer[6];

	for (int i = 0; i < 4; i++)
		cin >> sawtooth[i];

	idxPointer[0] = 2; // 1번 오른쪽
	idxPointer[1] = 6; // 2번 왼쪽
	idxPointer[2] = 2; // 2번 오른쪽
	idxPointer[3] = 6; // 3번 왼쪽
	idxPointer[4] = 2; // 3번 오른쪽
	idxPointer[5] = 6; // 4번 왼쪽

	// 회전 횟수
	int k;
	cin >> k;
	while (k--) {
		int position, direction;
		cin >> position >> direction;
		int rotatePos[4] = { 0, 0, 0, 0 };

		if (position == 1) {
			rotatePos[0] = -direction;

			if (sawtooth[0][idxPointer[0]] != sawtooth[1][idxPointer[1]]) {
				rotatePos[1] = direction;

				if (sawtooth[1][idxPointer[2]] != sawtooth[2][idxPointer[3]]) {
					rotatePos[2] = -direction;

					if (sawtooth[2][idxPointer[4]] != sawtooth[3][idxPointer[5]]) {
						rotatePos[3] = direction;
					}
				}
			}
		}
		else if (position == 2) {
			rotatePos[1] = -direction;

			if (sawtooth[0][idxPointer[0]] != sawtooth[1][idxPointer[1]])
				rotatePos[0] = direction;

			if (sawtooth[1][idxPointer[2]] != sawtooth[2][idxPointer[3]]) {
				rotatePos[2] = direction;
				if (sawtooth[2][idxPointer[4]] != sawtooth[3][idxPointer[5]]) {
					rotatePos[3] = -direction;
				}
			}
		}
		else if (position == 3) {
			rotatePos[2] = -direction;

			if (sawtooth[1][idxPointer[2]] != sawtooth[2][idxPointer[3]]) {
				rotatePos[1] = direction;
				if (sawtooth[0][idxPointer[0]] != sawtooth[1][idxPointer[1]]) {
					rotatePos[0] = -direction;
				}
			}
			
			if (sawtooth[2][idxPointer[4]] != sawtooth[3][idxPointer[5]]) {
				rotatePos[3] = direction;
			}
		}
		else if (position == 4) {
			rotatePos[3] = -direction;
			if (sawtooth[2][idxPointer[4]] != sawtooth[3][idxPointer[5]]) {
				rotatePos[2] = direction;
				if (sawtooth[1][idxPointer[2]] != sawtooth[2][idxPointer[3]]) {
					rotatePos[1] = -direction;
					if (sawtooth[0][idxPointer[0]] != sawtooth[1][idxPointer[1]]) {
						rotatePos[0] = direction;
					}
				}
			}
		}

		idxPointer[0] += rotatePos[0];
		idxPointer[1] += rotatePos[1];
		idxPointer[2] += rotatePos[1];
		idxPointer[3] += rotatePos[2];
		idxPointer[4] += rotatePos[2];
		idxPointer[5] += rotatePos[3];

		for (int i = 0; i < 6; i++)
			idxPointer[i] = checkRange(idxPointer[i]);
	}

	int ans = 0;
	ans += (sawtooth[0][(idxPointer[0] + 6) % 8] - '0') * 1;
	ans += (sawtooth[1][(idxPointer[2] + 6) % 8] - '0') * 2;
	ans += (sawtooth[2][(idxPointer[4] + 6) % 8] - '0') * 4;
	ans += (sawtooth[3][(idxPointer[5] + 2) % 8] - '0') * 8;

	cout << ans << '\n';
}