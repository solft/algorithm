package main

import (
	"encoding/base64"
	"fmt"
)

// 10935번 BASE64 인코딩
// 분류: 인코딩디코딩
// 문제:
//		BASE64 인코딩 결과 출력
// 풀이:
//		Go 라이브러리 이용
func main() {

	var str string
	_, _ = fmt.Scanln(&str)
	encoding := base64.StdEncoding.EncodeToString([]byte(str))

	fmt.Println(encoding)
}