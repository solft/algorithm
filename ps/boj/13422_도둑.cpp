#include <iostream>
using namespace std;

// 13422번 도둑
// 문제:
//		원형 배열의 부분합이 threshold 미만인 것의 개수를 구하는 문제
// 풀이:
//		우선 부분합이 필요하니 합배열을 만드는 아이디어에서 시작하여
//		초항 역할을 할 첫 원소부터 구한 뒤
//		구하기 쉬운 부분인 시작과 끝 부분을 포함하지 않는 부분부터 구하고
//		경계를 포함하는 부분을 규칙을 찾아 구해주면 된다.
//		구하면서 카운팅해도 되는데 그냥 다 구하고 카운팅했다.
//		한가지 주의할 점은 경우의 수를 세는 문제이므로
//		n == m일 경우 전체 케이스는 1가지거나 0가지인 것 체크해줘야 한다.

int t;
// n = 집의 개수, 
// m = 연속으로 훔칠 집의 개수, 
// k = 방범장치 threshold
int n, m, k; 
int house[100000];
// money[i] = house[i] ~ house[i - m + 1]까지 돈의 합
// money[m - 1] = house[0]부터 house[m - 1]
int money[100000]; 

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int ans = 0;
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &house[i]);
		// 처음 기준이 될 money[m-1] 구하기
		money[m - 1] = 0;
		for (int i = 0; i < m; i++)
			money[m - 1] += house[i];
		// 만약 m == n 인 경우 경우의 수는 1가지 아니면 0가지다
		if (m == n) {
			if (money[m - 1] < k)
				printf("1\n");
			else
				printf("0\n");
			continue;
		}
		// money[m] ~ money[n-1]까지 구하기
		for (int i = m; i < n; i++)
			money[i] = money[i - 1] - house[i - m] + house[i];
		// money[0] ~ money[m-2]까지 구하기
		for (int i = 0; i < m - 1; i++)
			money[i] = money[(n + i - 1) % n] + house[i] - house[(n + i - m) % n];
		for (int i = 0; i < n; i++)
			if (money[i] < k)
				ans++;
		printf("%d\n", ans);
	}
}