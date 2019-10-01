
// 17175번 피보나치는 지겨웡
// 분류: dp
// 문제:
//      피보나치 호출 횟수 구하기
// 풀이:
//      A(0) = 1, A(1) = 1
//      A(n) = A(n-2) + A(n-1) + 1
//      이 식으로 표현 가능하다.
val dp = Array<Int>(51) { -1 }

fun solution(a: Int): Int {
    if (dp[a] != -1)
        return dp[a]
    dp[a] = solution(a-2) + solution(a-1) + 1
    dp[a] %= 1_000_000_007
    return dp[a]
}

fun main() {
    dp[0] = 1
    dp[1] = 1
    val n = readLine()!!.toInt()
    println(solution(n))
}
