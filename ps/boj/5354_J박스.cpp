#include <iostream>
using namespace std;
// 5354�� J�ڽ�
// �з�: ����, �ݺ���
// ����:
//		�ش� ��翡 �°� ����ϱ�
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