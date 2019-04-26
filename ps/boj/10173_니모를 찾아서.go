package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)
// 10173번 니모를 찾아서
// 풀이:
//		간단 구현 문제
//		go 같은 경우 console에서 한 line을 입력 받는게 조금 귀찮다.
//		아래와 같은 방법으로 하면 마지막에 '\n'이 붙어 이걸 없애줘야한다.
//		fmt.Scanln()을 사용하면 space 기준으로도 입력이 바뀐다.
func main() {
	reader := bufio.NewReader(os.Stdin)
	for {
		var text string
		text, _ = reader.ReadString('\n')
		text = strings.Replace(text, "\n", "", -1)
		if text == "EOI" {
			break
		}
		text = strings.ToLower(text)
		if strings.Contains(text, "nemo") {
			fmt.Println("Found")
		} else {
			fmt.Println("Missing")
		}
	}
}