
// 2903번 중앙 이동 알고리즘
// 분류: 수학
// 문제 & 풀이:
//      규칙 f(n) = 2*f(n-1) - 1, f(1) = 3 에서
//      f(n) * f(n) 구하기
fun sol(i: Long): Long {
    if (i == 1L)
        return 3L
    return 2 * sol(i - 1) - 1L
}

fun main() {
    val n = readLine()!!.toLong()
    println(sol(n) * sol(n))
}
