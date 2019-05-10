#include <iostream>
using namespace std;
// 5354번 J박스
// 분류: 구현, 반복문
// 문제:
//		해당 모양에 맞게 출력하기
int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			printf("#");
		printf("\n");
		for (int k = 0; k < n-2; k++) {
			for (int i = 0; i < n; i++) {
				if (i == 0)
					printf("#");
				else if (i == n - 1)
					printf("#\n");
				else
					printf("J");
			}
		}
		
		if (n != 1) {
			for (int i = 0; i < n; i++)
				printf("#");
			printf("\n");
		}
		printf("\n");
	}
}