
// 12780번 원피스
// 분류: 문자열 검색
// 문제:
//      text에 pattern이 몇 번 나타나는지 구하는 문제
// 풀이:
//      KMP 사용해도 되지만 코틀린의 split을 활용하여 풀어보았다.
fun main() {
    val h = readLine()!!
    val n = readLine()!!
    val ans = h.split(n).size - 1
    println(ans)
}
