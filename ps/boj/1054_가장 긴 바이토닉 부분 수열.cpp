#include <iostream>
#include <algorithm>
using namespace std;

// 11054번 가장 긴 바이토닉 부분 수열
// 분류: DP
// 문제: 
//		주어진 수열에서 증가하다가 줄어드는(증가만 해도되고 감소만해도됨)
//		가장 긴 부분 수열의 길이 구하는 문제
// 풀이:
//		정방향으로 증가하는 부분 수열 길이 DP로 구하고
//		역방향으로 증가하는 부분 수열 길이 DP로 구해서
//		k번째 둘의 합이 가장 큰 곳에서 1 뺀 값이 가장 긴 바이토닉 부분 수열의 길이가 된다.
int num[1010];
int updp[1010];
int downdp[1010];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	for (int i = 1; i <= n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++)
			if(num[i] > num[j] && max < updp[j] + 1)
				max = updp[j] + 1;
		updp[i] = max;
	} 

	for (int i = n; i >= 1; i--) {
		int max = 0;
		for (int j = n + 1; j > i; j--)
			if (num[i] > num[j] && max < downdp[j] + 1)
				max = downdp[j] + 1;
		downdp[i] = max;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (ans < updp[i] + downdp[i])
			ans = updp[i] + downdp[i];
	cout << ans - 1 << '\n';
}