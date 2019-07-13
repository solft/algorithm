#include <iostream>
#include <stack>
using namespace std;

// 10829번 이진수 변환
// 분류: 이진수
// 문제:
//		주어진 수를 이진수로 변환하는 문제
// 풀이:
//		2로 나눠가며 나머지를 저장해둔다.
//		문제에서 범위가 1 ~ 100,000,000,000,000까지여서 상관 없는데
//		내가 쓴 코드는 0일때 안된다. 그래서 답은 되는데 불안정한 상태다.
typedef long long ll;

int main() {
	ll N; 
	cin >> N;
	stack<int> ans;
	while (N != 0LL) {
		ans.push(N % 2LL);
		N /= 2LL;
	}
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
}