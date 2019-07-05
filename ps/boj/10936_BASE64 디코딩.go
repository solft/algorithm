package main

import (
	"encoding/base64"
	"fmt"
)

// 10936번 BASE64 디코딩
// 분류: 인코딩디코딩
// 문제:
//		BASE64 디코딩 결과 출력
// 풀이:
//		Go 라이브러리 이용
func main() {

	var str string
	_, _ = fmt.Scanln(&str)
	decoding, _ := base64.StdEncoding.DecodeString(str)
	ans := string(decoding)
	fmt.Println(ans)
}