#include <iostream>
using namespace std;

// 4287번 Word Ratios
// 문제:
//		두 문자 사이의 변화 규칙을 찾아 다른 한 문자에 적용시키는 문제
// 풀이:
//		a[i] : b[i] = c[i] : 답[i] 이므로
//		a[i] - b[i] = c[i] - 답[i]
//		답[i] = c[i] - a[i] + b[i]
//		여기서 답[i]가 'a' ~ 'z' 범위를 벗어나는 경우 수정해주면 된다.
// 주의:
//		char로 잡고 위의 연산을 하면 연산중 범위를 벗어나 음수가 되는
//		경우가 있으니 마음 편하게 int로 잡고 char로 변환해 출력하였다.
int main() {
	string a, b, c;
	while (true) {
		cin >> a;
		if (a == "#")
			break;
		cin >> b >> c;

		cout << a << " " << b << " " << c << " ";

		for (int i = 0; i < a.length(); i++) {
			int res = c[i] + b[i] - a[i];
			if (res > 'z')
				res -= 26;
			else if (res < 'a')
				res += 26;
			cout << char(res);
		}
		cout << endl;
	}
}