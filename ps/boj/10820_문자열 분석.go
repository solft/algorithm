package main

import (
	"bufio"
	"fmt"
	"os"
)

// 10820번 문자열 분석
// 문제:
// 		문자열 N개 입력받아 소문자, 대문자, 숫자, 공백 개수를 출력하는 문제
// 풀이:
//		단순 구현. 근데 fmt.Scanln()으로는 입력이 이상하게 되어서
//		bufio.NewReader(os.Stdin)을 이용하여 '\n'까지 입력 받는걸 처음 이용해 봤다.
//		이 문제도 입력에 몇 개인지 주어지지 않은 문제여서
//		결과가 0 0 0 0 일때 반복문을 탈출하도록 하니 해결되었다.
func main() {
	reader := bufio.NewReader(os.Stdin)

	for {
		line, _ := reader.ReadString('\n')

		var small, big, num, space int

		for _, char := range line {
			if char >= 'a' && char <= 'z' {
				small++
			} else if char >= 'A' && char <= 'Z' {
				big ++
			} else if char >= '0' && char <= '9' {
				num++
			} else if char == ' ' {
				space++
			}
		}

		if small == 0 && big == 0 && num == 0 && space == 0 {
			break
		} else {
			fmt.Printf("%d %d %d %d", small, big, num, space)
			fmt.Println()
		}
	}
}