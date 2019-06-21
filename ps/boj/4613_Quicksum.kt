
// 4613번 Quicksum
// 분류: 문자열
// 문제:
//      문자열의 인덱스*문자 번호를 구하는 문제
// 풀이:
//      A=1 ~ Z=26로 변환해서 곱해준다.
fun main() {
    while(true){
        val str = readLine()!!

        if(str == "#")
            break

        var ans = 0
        for (i in 0 until str.length){
            if (str[i] != ' ')
                ans += (i+1)*(str[i] - 'A' + 1)
        }

        println(ans)
    }
}
