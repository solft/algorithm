package main

import (
	"fmt"
	"strconv"
	"strings"
)

// 4564번 숫자 카드놀이
// 풀이:
// 		간단한 구현 문제
//		golang
//			string to int : strconv.Atoi("123")
//			int to string : strconv.Itoa(123)
func main() {
	var num int
	for {
		_, _ = fmt.Scanf("%d", &num)

		if num == 0 {
			break
		}

		for {

			if num < 10 {
				fmt.Println(num)
				break
			} else {
				fmt.Printf("%d ", num)
			}

			str := strconv.Itoa(num)
			strArr := strings.Split(str, "")
			num = 1
			for _, e := range strArr {
				temp, _ := strconv.Atoi(e)
				num *= temp
			}
		}
	}
}