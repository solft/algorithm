
// 13410번 거꾸로 구구단
// 분류: 반복문, 뒤집기
// 문제:
//      구구단의 결과에서 거꾸로 쓴 값의 최댓값 출력
// 풀이:
//      가장 큰 값을 저장한다.
fun main() {
    val num = readLine()!!.split(" ").map { it.toInt() }
    var ans = 0
    for(j in 1 .. num[1]){
        val gugudan = (num[0]*j).toString().reversed().toInt()
        if (ans < gugudan)
            ans = gugudan
    }
    println(ans)
}
