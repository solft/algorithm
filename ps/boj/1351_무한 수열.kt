
// 1351번 무한 수열
// 분류: DP
// 문제:
//      A(0) = 1
//      A(i) = A(i/P) + A(i/Q) 일 때
//      A(n)을 구하는 문제
// 풀이:
//      A(i) 구해둔걸 저장해 둔다.
var N = 0L
var P = 0L
var Q = 0L

val dp = mutableMapOf<Long, Long>()

fun sol(i: Long): Long {
    if (dp.contains(i))
        return dp[i]!!
    dp[i] = sol(i/P) + sol(i/Q)
    return dp[i]!!
}

fun main() {
    dp[0] = 1
    val inputs = readLine()!!.split(" ").map { it.toLong() }.toTypedArray()
    N = inputs[0]
    P = inputs[1]
    Q = inputs[2]

    println(sol(N))
}
