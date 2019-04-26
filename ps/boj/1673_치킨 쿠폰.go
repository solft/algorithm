package main

import "fmt"

// 1673번 치킨 쿠폰
// 문제:
// 		치킨 쿠폰 1장당 치킨 1마리 치킨 주문시 도장 1개 -> 최대 치킨 몇 마리
// 		n = 치킨 쿠폰, k = 쿠폰 받기 위한 도장 수
// 풀이:
//		그냥 문제 조건대로 구현해도 시간 안에 풀 수 있다.
//		단순히 치킨사서 받은 도장으로만 다음 치킨을 계산하면 이전의 도장을
//		계산하지 못한다. 그래서 도장을 저장할 변수를 만들어 두고
//		도장이 쭉 사용하도록 한다.
//		탈출 조건은 남은 쿠폰으로 치킨을 사지 못할 때 탈출한다.
//		문제에서 입력의 끝 조건이 따로 주어지지 않고
//		그냥 입력이 없으면 종료해야 하므로 Scanln의 리턴 값을 이용했다.
func main() {

	var n, k int

	for {
		check, _ := fmt.Scanln(&n, &k)
		if check == 0 {
			break
		}

		ans := 0
		coupon := n
		stamp := 0

		for {
			ans += coupon
			stamp += coupon
			coupon = stamp / k
			stamp = stamp % k
			if coupon <= 0 {
				break
			}
		}
		fmt.Println(ans)
	}
}